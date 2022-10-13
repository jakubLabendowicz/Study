const { Track, validate } = require("../models/track")
const { Favorite } = require("../models/favorite")


const createTrack = async (req, res) => {
    try {
        // const { error } = validate(req.body)
        // if (error) {
        //     return res.status(400).send({ message: error.details[0].message })
        // }

        // if(req.body.spotifyId) {
        //     let track = await Track.findOne({ spotifyId: req.body.spotifyId })
        //     if (track)
        //         return res
        //             .status(409)
        //             .send({ success: false, message: "Utwór o takim spotifyId już istnieje" })
        // }

        let track = await new Track({ ...req.body }).save()
        res.status(201).send({ success: true, message: "Utworzono utwór", track: track })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera" })
    }
}

const updateTrack = async (req, res) => {
    try {
        let track = await Track.findOne({ _id: req.body._id })
        if (!track)
            return res
                .status(409)
                .send({ success: false, message: "Utwór o takim id nie istnieje" })
        track = await Track.findOneAndUpdate({ _id: req.body._id }, req.body)
        res.status(201).send({ success: true, message: "Zaktualizowano utwór", track: track })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera" })
    }
}

const deleteTrack = async (req, res) => {
    try {
        const track = await Track.findOne({ _id: req.params.id })
        if (!track)
            return res
                .status(409)
                .send({ success: false, message: "Utwór o takim id nie istnieje" })
        await Track.findOneAndRemove({ _id: req.params.id })
        res.status(201).send({ success: true, message: "Usunięto utwór"})
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera" })
    }
}

const selectTrack = async (req, res) => {
    try {
        const track = await Track.findOne({ _id: req.params.id })
        let favorite = await Favorite.findOne({ userId: req.query.userId, trackId: req.params.id })
        let trackWithFavorite;
            if(favorite != null) {
                trackWithFavorite = {
                    _id: track._id,
                    name: track.name,
                    artists: track.artists,
                    spotifyId: track.spotifyId,
                    previewUrl: track.previewUrl,
                    popularity: track.popularity,
                    durationMs: track.durationMs,
                    image: track.image,
                    favorite: true
                }
            } else {
                trackWithFavorite = {
                    _id: track._id,
                    name: track.name,
                    artists: track.artists,
                    spotifyId: track.spotifyId,
                    previewUrl: track.previewUrl,
                    popularity: track.popularity,
                    durationMs: track.durationMs,
                    image: track.image
                }
            }
        
        res.send({ success: true, message: "Wyszukano utwór", track: trackWithFavorite })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera" })
    }
}

const selectTracks = async (req, res) => {
    try {
        console.log(req.query.userId);
        const tracks = await Track.find()

        let tracksWithFavorites = [];
        for(let track of tracks ) {
            let favorite = await Favorite.findOne({ userId: req.query.userId, trackId: track._id })
            let trackWithFavorite;
            if(favorite != null) {
                trackWithFavorite = {
                    _id: track._id,
                    name: track.name,
                    artists: track.artists,
                    spotifyId: track.spotifyId,
                    previewUrl: track.previewUrl,
                    popularity: track.popularity,
                    durationMs: track.durationMs,
                    image: track.image,
                    favorite: true
                }
            } else {
                trackWithFavorite = {
                    _id: track._id,
                    name: track.name,
                    artists: track.artists,
                    spotifyId: track.spotifyId,
                    previewUrl: track.previewUrl,
                    popularity: track.popularity,
                    durationMs: track.durationMs,
                    image: track.image
                }
            }
            tracksWithFavorites.push(trackWithFavorite);
        }

        res.send({ success: true, message: "Wyszukano utwory", tracks: tracksWithFavorites })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera" })
    }
}

module.exports = {createTrack, updateTrack, deleteTrack, selectTrack, selectTracks}


// body: {
//     data: {},
//     where: {},
//     group_by: {},
//     join: {}
// }