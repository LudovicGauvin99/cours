------------------------------------------------------------------------
-- Création de la base de données 
------------------------------------------------------------------------
drop database if exists basket; -- supprime si la base existe
CREATE database if not exists basket; -- crée la base de donnée 
use basket; -- indique qu'on travail sur la base de donnée 

------------------------------------------------------------------------
-- création des tables 
------------------------------------------------------------------------
CREATE TABLE matchs(
        idmatch Int  Auto_increment  NOT NULL , -- création d'attribut syntaxe : "nom Attribut" "type" "null ou not null" 
        dateMatch    Date NOT NULL 
	,CONSTRAINT matchs_PK PRIMARY KEY (idmatch) -- défini la clé primaire 
)ENGINE=InnoDB;

CREATE TABLE logo(
        idlogo     Int  Auto_increment  NOT NULL ,
        logoNom    Varchar (50) NOT NULL ,
        logoTaille Varchar (25) NOT NULL ,
        logoType   Varchar (25) NOT NULL ,
        logoDesc   Varchar (100) NOT NULL ,
        logoBlob   Blob NOT NULL
	,CONSTRAINT logo_PK PRIMARY KEY (idlogo)
)ENGINE=InnoDB;

CREATE TABLE equipes(
        idequipe  Int  Auto_increment  NOT NULL ,
        nomEquipe Varchar (20) NOT NULL ,
        region    Varchar (20) NOT NULL ,
        idlogo    Int  NULL
	,CONSTRAINT equipes_PK PRIMARY KEY (idequipe)

	,CONSTRAINT equipes_logo_FK FOREIGN KEY (idlogo) REFERENCES logo(idlogo) -- défini une clé étrangère
	,CONSTRAINT equipes_logo_AK UNIQUE (idlogo) 
)ENGINE=InnoDB;

CREATE TABLE dispute(
        idmatch  Int NOT NULL ,
        idequipe Int NOT NULL ,
        premierQuartTemps    int (3) NOT NULL,
        deuxiemeQuartTemps    int (3) NOT NULL,
        troisiemeQuartTemps    int (3) NOT NULL,
        quatriemeQuartTemps    int (3) NOT NULL
	,CONSTRAINT dispute_PK PRIMARY KEY (idmatch,idequipe)

	,CONSTRAINT dispute_matchs_FK FOREIGN KEY (idmatch) REFERENCES matchs(idmatch)
	,CONSTRAINT dispute_equipes0_FK FOREIGN KEY (idequipe) REFERENCES equipes(idequipe)
)ENGINE=InnoDB;

-----------------------------------------------------------------------------
-- modification d'une table si besoin 
-----------------------------------------------------------------------------
ALTER TABLE `basket`.`logo` 
CHANGE COLUMN `logoNom` `logoNom` VARCHAR(100) NOT NULL ,
CHANGE COLUMN `logoTaille` `logoTaille` int() NOT NULL ;

-----------------------------------------------------------------------------
-- supprime une colonne 
-----------------------------------------------------------------------------
DROP COLUMN `logoDesc`;