"use strict";

module.exports = function(sequelize, DataTypes) {
  var registro = sequelize.define("registro", {
    id_registro: {
      type: DataTypes.INTEGER,
         autoIncrement: true,
         primaryKey: true
    },
    jugera:{
      type : DataTypes.INTEGER
    },
    jugo:{
      type : DataTypes.INTEGER
    }
    }, { freezeTableName: true,
    tableName: 'registro',
    });
//Tarjeta.removeAttribute('id');
  return registro;
};
