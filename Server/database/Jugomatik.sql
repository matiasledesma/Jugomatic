create database Jugomatik;

use Jugomatik;

create table Jugera (
	id_jugera int not null auto_increment,
    primary key (id_jugera),
    escuela varchar(60)
);

create table Jugo (
	id_jugo int not null auto_increment,
    primary key(id_jugo),
    sabor_jugo varchar(20)
);

create table registro (
	id_registro int not null auto_increment,
    primary key(id_registro),
    jugera int(11) not null,
    jugo int(11) not null,
    created_at datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
    key jugera_id (jugera),
    key jugo_id (jugo),
    CONSTRAINT registro_jugera FOREIGN KEY (jugera) REFERENCES Jugera (id_jugera) ON DELETE NO ACTION ON UPDATE NO ACTION,
	CONSTRAINT registro_jugo FOREIGN KEY (jugo) REFERENCES Jugo (id_jugo) ON DELETE NO ACTION ON UPDATE NO ACTION
);