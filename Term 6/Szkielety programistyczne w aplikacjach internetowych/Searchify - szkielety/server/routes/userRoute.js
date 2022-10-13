const router = require("express").Router()
const {createUser, selectUser, selectUsers, checkUser} = require("../services/userService")


router.post("/users", async (req, res) => {
    createUser(req, res)
})

router.get("/users/:userid",  async (req, res) => {
    selectUser(req, res)
})

router.get("/users",  async (req, res) => {
    selectUsers(req, res)
})

router.post("/auth", async (req, res) => {
    checkUser(req, res)
})

module.exports = router