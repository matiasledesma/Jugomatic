var express = require('express');
var router = express.Router();
var models = require("../mysql");
const dbConnection = require("../mysql/dbConnection");

const connection = dbConnection();


/* GET users listing. */
router.get('/', (req, res) => {
  connection.query('select registro.id_registro, jugera.escuela, jugo.sabor_jugo, registro.created_at, registro.update_at from registro inner join jugera on registro.jugera = jugera.id_jugera inner join jugo on registro.jugo = jugo.id_jugo order by jugera.escuela asc', (err, result) => {
      res.status(200).jsonp(result);
  })
  console.log('llego')
});
//Obtener
router.get('/:id', function(req, res, next){

  let id = req.params.id;
  models.registro.findOne({
    where: {
      id_registro: id
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
  models.usuario.destroy({
    where: {
      id_registro: id
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
  let registro = req.body;
  models.registro.create(registro).then(result => {
    res.status(200).jsonp({status:true , response:"se creo con exito"});
  })

});
module.exports = router;
