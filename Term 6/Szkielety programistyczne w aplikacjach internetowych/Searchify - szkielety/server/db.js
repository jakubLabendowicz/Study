const mongoose = require("mongoose")
module.exports = () => {
    const connectionParams = {
        useNewUrlParser: true,
        useUnifiedTopology: true,
    }
    try {
        mongoose.connect(process.env.DB, connectionParams)
        console.log("Połączono z bazą danych")
    } catch (error) {
        console.log(error);
        console.log("Problem z połączeniem do bazy!")
    }
}
