var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var cors = require('cors')

var indexRouter = require('./routes/index');
var registroRouter = require('./routes/registro');
var jugeraRouter = require('./routes/jugera');
var jugoRouter = require('./routes/jugo');

var app = express();

app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/registro', registroRouter);
app.use('/jugera', jugeraRouter);
app.use('/jugo', jugoRouter);
module.exports = app;
