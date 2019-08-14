"use strict";

module.exports = function(sequelize, DataTypes) {
  var Jugera = sequelize.define("Jugera", {
    id_jugera: {
      type: DataTypes.INTEGER,
         autoIncrement: true,
         primaryKey: true
    },
    escuela:{
        type : DataTypes.STRING
    }
  }, { freezeTableName: true,
  tableName: 'Jugera'});
//Tarjeta.removeAttribute('id');
  return Jugera;
};
