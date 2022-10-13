const { Favorite, validate } = require("../models/favorite")
const { Track } = require("../models/track")

const createFavorite = async (req, res) => {
    try {
        // const { error } = validate(req.body)
        // if (error) {
        //     return res.status(400).send({ message: error.details[0].message })
        // }
        const favorite = await Favorite.findOne({ userId: req.body.userId, trackId: req.body.trackId })
        if (favorite)
            return res
                .status(409)
                .send({ message: "Ulubiony utwór użytkownika o takim trackId już istnieje" })
        await new Favorite({ userId: req.body.userId, trackId: req.body.trackId }).save()
        res.status(201).send({ message: "Utworzono ulubiony utwór użytkownika" })
    } catch (error) {
        res.status(500).send({ message: "Wewnętrzny błąd serwera" })
    }
}

const deleteFavorite = async (req, res) => {
    try {
        if(req.body.userId == "all") {
            const favorites = await Favorite.find({trackId: req.body.trackId })
            if (!favorites)
                return res
                    .status(409)
                    .send({ message: "Ulubione utwór użytkownika o takim trackId nie istnieją" })
            await Favorite.findOneAndRemove({ trackId: req.body.trackId })
            res.status(201).send({ message: "Usunięto ulubione utwory użytkownika" })
        } else if(req.body.userId != "all") {
            const favorite = await Favorite.findOne({ userId: req.body.userId, trackId: req.body.trackId })
            if (!favorite)
                return res
                    .status(409)
                    .send({ message: "Ulubiony utwór użytkownika o takim trackId nie istnieje" })
            await Favorite.findOneAndRemove({ userId: req.body.userId, trackId: req.body.trackId })
            res.status(201).send({ message: "Usunięto ulubiony utwór użytkownika" })
        } 
        
    } catch (error) {
        res.status(500).send({ message: "Wewnętrzny błąd serwera" })
    }
}

const selectUserFavorites = async (req, res) => {
    try {
        let favorites = await Favorite.find({ userId: req.params.userId })
        let favoritesWithTracks = [];
        for(let favorite of favorites ) {
            let track = await Track.findOne({ _id: favorite.trackId })
            let favoriteWithTrack = {
                _id: favorite._id,
                userId: favorite.userId,
                trackId: favorite.trackId,
                __v: favorite.__v,
                track: track
            };
            favoritesWithTracks.push(favoriteWithTrack);
        }

        res.send({ success: true, message: "Wyszukano ulubione utwory użytkownika", favorites: favoritesWithTracks })
    } catch (error) {
        res.status(500).send({ message: "Wewnętrzny błąd serwera" })
    }
}



module.exports = {createFavorite, deleteFavorite, selectUserFavorites}