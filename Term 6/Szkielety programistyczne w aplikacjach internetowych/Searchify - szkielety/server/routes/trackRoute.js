const router = require("express").Router()
const {createTrack, updateTrack, deleteTrack, selectTrack, selectTracks} = require("../services/trackService")

router.post("/tracks", async (req, res) => {
    createTrack(req, res)
})

router.put("/tracks", async (req, res) => {
    updateTrack(req, res)
})

router.delete("/tracks/:id", async (req, res) => {
    deleteTrack(req, res)
})

router.get("/tracks/:id", async (req, res) => {
    selectTrack(req, res)
})

router.get("/tracks", async (req, res) => {
    selectTracks(req, res)
})

module.exports = router