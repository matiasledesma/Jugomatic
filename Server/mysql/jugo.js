"use strict";

module.exports = function(sequelize, DataTypes) {
  var Jugo = sequelize.define("Jugo", {
    id_jugo: {
      type: DataTypes.INTEGER,
         autoIncrement: true,
         primaryKey: true
    },
    sabor_jugo:{
        type : DataTypes.STRING
    }
  }, { freezeTableName: true,
  tableName: 'Jugo'});




//Tarjeta.removeAttribute('id');
  return Jugo;
};
