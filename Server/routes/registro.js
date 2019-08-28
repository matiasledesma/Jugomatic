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
});


router.get('/contar_jugeras/:jugera', (req, res) => {
  var jugera = req.params.jugera;
  
  connection.query('select count(id_registro) as resultado from registro inner join jugera on jugera=id_jugera where id_jugera = '+ jugera + ';', (err, result) => {
      res.status(200).jsonp( 
        result[0]
      );
  })
});

router.get('/contar_jugos/:jugo', (req, res) => {
  var jugo = req.params.jugo;
  
  connection.query('select count(id_registro) as resultado from registro inner join jugo on jugo=id_jugo where id_jugo = '+ jugo + ';', (err, result) => {
      res.status(200).jsonp( 
        result[0]
      );
  })
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
