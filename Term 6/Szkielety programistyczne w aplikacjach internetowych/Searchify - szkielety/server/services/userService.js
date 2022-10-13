const { User, validate } = require("../models/user")
const { Favorite} = require("../models/favorite")
const { Track } = require("../models/track")
const bcrypt = require("bcrypt")
const Joi = require("joi")


const createUser = async (req, res) => {
    try {
        const { error } = validate(req.body)
        if (error)
            return res.status(400).send({ success: false, message: error.details[0].message})
        const user = await User.findOne({ email: req.body.email })
        if (user)
            return res
                .status(409)
                .send({ success: false, message: "Użytkownik o takim emailu istnieje!"})
        const salt = await bcrypt.genSalt(Number(process.env.SALT))
        const hashPassword = await bcrypt.hash(req.body.password, salt)
        await new User({ ...req.body, password: hashPassword }).save()
        res.status(201).send({ success: true, message: "Utworzono użytkownika"})
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera"})
    }
}

const selectUser = async (req, res) => {
    try {
        const user = await User.findOne({ _id: req.params.userid })
        if (!user)
            return res
                .status(409)
                .send({ success: false, message: "Użytkownik o takim id nie istnieje" })
        res.send({ success: true, message: "Wyszukano użytkownika", user: user })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera"})
    }
}

const selectUsers = async (req, res) => {
    try {
        const users = await User.find()
        let usersWithFavorites = [];
        for(let user of users ) {

            let favorites = await Favorite.find({ userId: user._id })
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

            let userWithFavorites = {
                _id: user._id,
                firstName: user.firstName,
                lastName: user.lastname,
                email: user.email,
                password: user.password,
                favorites: favoritesWithTracks
            };
            usersWithFavorites.push(userWithFavorites);
        }
        

        res.send({ success: true, message: "Wyszukano użytkowników", users: usersWithFavorites })
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera"})
    }
}

const checkUser = async (req, res) => {
    try {
        const schema = Joi.object({
            email: Joi.string().email().required().label("Email"),
            password: Joi.string().required().label("Password"),
        })
        const { error } = schema.validate(req.body);
        if (error)
            return res.status(400).send({ success: false, message: error.details[0].message})
        const user = await User.findOne({ email: req.body.email })
        if (!user)
            return res.status(401).send({ success: false, message: "Błędny email lub hasło!"})
        const validPassword = await bcrypt.compare(
            req.body.password,
            user.password
        )
        if (!validPassword)
            return res.status(401).send({ success: false, message: "Błędny email lub hasło!"})
        const token = user.generateAuthToken();
        res.status(200).send({ success: true, message: "Zalogowano!", data: token, user: {_id: user._id}})
    } catch (error) {
        res.status(500).send({ success: false, message: "Wewnętrzny błąd serwera"})
    }
}

module.exports = {createUser, selectUser, selectUsers, checkUser}