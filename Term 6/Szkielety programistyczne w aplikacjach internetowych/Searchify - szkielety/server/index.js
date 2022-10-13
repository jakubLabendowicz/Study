require('dotenv').config()
const express = require('express')
const app = express()
const cors = require('cors')
app.use(express.json())
app.use(cors())

// db
const connection = require('./db')
connection()

// routes
const userRoutes = require("./routes/userRoute")
const trackRoutes = require("./routes/trackRoute")
const favoriteRoutes = require("./routes/favoriteRoute")
app.use("/api", userRoutes)
app.use("/api", trackRoutes)
app.use("/api", favoriteRoutes)


const port = process.env.PORT || 8080
app.listen(port, () => console.log(`Nasłuchiwanie na porcie ${port}`))