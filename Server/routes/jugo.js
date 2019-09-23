var express = require('express');
var router = express.Router();
var models = require("../mysql");
const dbConnection = require("../mysql/dbConnection");

const connection = dbConnection();
/* GET users listing. */
router.get('/', function(req, res) {
  connection.query('select * from jugo', (err, result) => {
    res.status(200).jsonp(result);
})
});
//Obtener
router.get('/:id', function(req, res, next){

  let id = req.params.id;
  models.posteo.findOne({
    where: {
      id_jugo: id
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
  models.Jugo.destroy({
    where: {
      id_posteo: id
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
  let Jugo = req.body;
  connection.query('INSERT INTO jugo (sabor_jugo) values ("'+ Jugo.sabor_jugo + '");', (err, result) => {
    res.status(200).jsonp( 
      result[0]
    );
    })
});
module.exports = router;
