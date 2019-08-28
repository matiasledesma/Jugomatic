var express = require('express');
var router = express.Router();
var models = require("../mysql");
const dbConnection = require("../mysql/dbConnection");

const connection = dbConnection();
/* GET users listing. */
router.get('/', function(req, res) {
  connection.query('select * from Jugera', (err, result) => {
    res.status(200).jsonp(result);
})
});
//Obtener
router.get('/:id', function(req, res, next){

  let id = req.params.id;
  models.Jugera.findOne({
    where: {
      id_jugera: id
    }
  }).then(result => {
    if(result== null){
      res.status(200).jsonp("no existe");
    }
    res.status(200).jsonp(result);
  })
});
//Eliminar
router.delete('/:id', function(req, res, next){

  let id = req.params.id;
  models.Jugera.destroy({
    where: {
      id_jugera: id
    }
  }).then(result => {
    if(result== null){
      res.status(200).jsonp("no existe");
    }
    res.status(200).jsonp(result);
  })
});
//Post
router.post('/', function(req, res, next){
  let Jugera = req.body;
  models.Jugera.create(Jugera).then(result => {
    res.status(200).jsonp({status:true , response:"se creo con exito"});
  })

});
module.exports = router;
