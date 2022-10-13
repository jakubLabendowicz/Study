const mongoose = require("mongoose")

const trackSchema = new mongoose.Schema({
    name: { type: String, required: true },
    artists: { type: String, required: true },
    spotifyId: { type: String, required: false },
    previewUrl: { type: String, required: false },
    popularity: { type: String, required: false },
    durationMs: { type: String, required: false },
    image: { type: String, required: false }
})

const Track = mongoose.model("Track", trackSchema)

const validate = (data) => {
    const schema = Joi.object({
        name: Joi.string().required().label("name"),
        artists: Joi.string().required().label("artists"),
        spotifyId: Joi.string().required().label("spotifyId"),
        previewUrl: Joi.string().label("previewUrl"),
        popularity: Joi.string().label("popularity"),
        durationMs: Joi.string().label("durationMs"),
        image: Joi.string().label("image")
    })
    return schema.validate(data)
}

module.exports = { Track, validate }
