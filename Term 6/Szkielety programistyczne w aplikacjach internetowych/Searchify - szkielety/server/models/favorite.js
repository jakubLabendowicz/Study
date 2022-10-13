const mongoose = require("mongoose")

const favoriteSchema = new mongoose.Schema({
    userId: { type: String, required: true },
    trackId: { type: String, required: true }
})

const Favorite = mongoose.model("Favorite", favoriteSchema)

const validate = (data) => {
    const schema = Joi.object({
        userId: Joi.string().required().label("UserId"),
        trackId: Joi.string().required().label("TrackId")
    })
    return schema.validate(data)
}

module.exports = { Favorite, validate }
