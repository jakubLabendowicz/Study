const router = require("express").Router()
const {createFavorite, deleteFavorite, selectUserFavorites} = require("../services/favoriteService")

router.post("/favorites", async (req, res) => {
    createFavorite(req, res)
})

router.delete("/favorites", async (req, res) => {
    deleteFavorite(req, res)
})

router.get("/users/:userId/favorites", async (req, res) => {
    selectUserFavorites(req, res)
})

module.exports = router