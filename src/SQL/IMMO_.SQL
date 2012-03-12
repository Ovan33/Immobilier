-- -----------------------------------------------------------------------------
--             Génération d'une base de données pour
--                           PostgreSQL
--                        (12/3/2012 14:00:20)
-- -----------------------------------------------------------------------------
--      Nom de la base : IMMO
--      Projet : AgImmo
--      Auteur : Gilles Coulais
--      Date de dernière modification : 12/3/2012 13:57:57
-- 		Testé avec succès sur PostGreSQL 8.4.11
--		
--		Ce script crée les tables et contraintes associées
--		La base doit préalablement exister
--
--		/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
--			 		Si vous avez déjà exécuté ce script
-- 		Toutes les données présentes dans la base seront effacées
--		/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
-- -----------------------------------------------------------------------------

-- -----------------------------------------------------------------------------
--       SUPPRESSION DES TABLES et CONTRAINTES EXISTANTES
-- -----------------------------------------------------------------------------
drop index i_fk_biens_clients cascade ;
drop index i_fk_biens_villes cascade ;
drop index i_fk_clients_agents cascade ;
drop index i_fk_clients_villes cascade ;
drop index i_fk_souhaits_clients cascade ;
drop index i_fk_villes_SOUHAITEES_souhait cascade ;
drop index i_fk_villes_SOUHAITEES_villes cascade ;
drop index i_fk_visites_biens cascade ;
drop index i_fk_visites_souhaits cascade ;

alter table villes_souhaitees drop constraint pk_villes_souhaitees cascade ;
alter table biens drop constraint pk_biens cascade ;
alter table clients drop constraint pk_clients cascade ;
alter table souhaits drop constraint pk_souhaits cascade ;
alter table villes drop constraint pk_villes cascade ;
alter table visites drop constraint pk_visites cascade ;

drop table visites CASCADE ;
drop table clients CASCADE ;
drop table biens CASCADE ;
drop table agents CASCADE ;
drop table souhaits CASCADE ;
drop table villes CASCADE ;
drop table villes_SOUHAITEES CASCADE ;

-- drop database IMMO ;

-- -----------------------------------------------------------------------------
--       CREATION DE LA BASE 
-- -----------------------------------------------------------------------------
-- CREATE DATABASE IMMO ;

-- -----------------------------------------------------------------------------
--       TABLE : VISITES
-- -----------------------------------------------------------------------------
CREATE TABLE VISITES
(
	NUM_V serial NOT NULL  ,
	NUM_S int4 NOT NULL  ,
	NUM_B int4 NOT NULL  ,
	DATE_V date NOT NULL  ,
	HEURE_V time NOT NULL  ,
		CONSTRAINT PK_VISITES PRIMARY KEY (NUM_V)
) ;

-- -----------------------------------------------------------------------------
--       INDEX DE LA TABLE VISITES
-- -----------------------------------------------------------------------------
CREATE  INDEX I_FK_VISITES_SOUHAITS ON VISITES (NUM_S) ;
CREATE  INDEX I_FK_VISITES_BIENS ON VISITES (NUM_B) ;

-- -----------------------------------------------------------------------------
--       TABLE : BIENS
-- -----------------------------------------------------------------------------
CREATE TABLE BIENS
(
	NUM_B serial NOT NULL  ,
	NUM_V int4 NOT NULL  ,
	NUM_C int4 NOT NULL  ,
	PRIX_VENTE_B char(32) NOT NULL  ,
	DATE_MISE_EN_VENTE_B date NOT NULL  ,
	SURFACE_HAB_B char(32) NOT NULL  ,
	SURFACE_JARDIN_B char(32) NOT NULL ,   
		CONSTRAINT PK_BIENS PRIMARY KEY (NUM_B)
) ;

-- -----------------------------------------------------------------------------
--       INDEX DE LA TABLE BIENS
-- -----------------------------------------------------------------------------
CREATE  INDEX I_FK_BIENS_VILLES ON BIENS (NUM_V) ;
CREATE  INDEX I_FK_BIENS_CLIENTS ON BIENS (NUM_C) ;

-- -----------------------------------------------------------------------------
--       TABLE : SOUHAITS
-- -----------------------------------------------------------------------------
CREATE TABLE SOUHAITS
(
	NUM_S serial NOT NULL  ,
	NUM_C int4 NOT NULL  ,
	BUDGET_MAX_S char(32) NULL  ,
	SURFACE_HAB_MIN_S char(32) NULL  ,
	SURFACE_JARDIN_MIN_S char(32) NULL  ,
		CONSTRAINT PK_SOUHAITS PRIMARY KEY (NUM_S)
) ;

-- -----------------------------------------------------------------------------
--       INDEX DE LA TABLE SOUHAITS
-- -----------------------------------------------------------------------------
CREATE  INDEX I_FK_SOUHAITS_CLIENTS ON SOUHAITS (NUM_C) ;

-- -----------------------------------------------------------------------------
--       TABLE : AGENTS
-- -----------------------------------------------------------------------------
CREATE TABLE AGENTS
(
	NUM_A serial NOT NULL  ,
	PRENOM_A varchar(20) NOT NULL  ,
		CONSTRAINT PK_AGENTS PRIMARY KEY (NUM_A)
) ;

-- -----------------------------------------------------------------------------
--       TABLE : CLIENTS
-- -----------------------------------------------------------------------------
CREATE TABLE CLIENTS
(
	NUM_C serial NOT NULL  ,
	NUM_V int4 NOT NULL  ,
	NUM_A int4 NULL  ,
	NOM_C varchar(20) NOT NULL  ,
	ADRESSE_C varchar(50) NOT NULL  ,
	TEL_C char(10) NOT NULL ,
		CONSTRAINT PK_CLIENTS PRIMARY KEY (NUM_C)
) ;

-- -----------------------------------------------------------------------------
--       INDEX DE LA TABLE CLIENTS
-- -----------------------------------------------------------------------------
CREATE  INDEX I_FK_CLIENTS_VILLES ON CLIENTS (NUM_V) ;
CREATE  INDEX I_FK_CLIENTS_AGENTS ON CLIENTS (NUM_A) ;

-- -----------------------------------------------------------------------------
--       TABLE : VILLES
-- -----------------------------------------------------------------------------
CREATE TABLE VILLES
(
	NUM_V serial NOT NULL  ,
	NOM_V varchar(40) NOT NULL  ,
	CODE_POSTAL_V char(5) NOT NULL ,
		CONSTRAINT PK_VILLES PRIMARY KEY (NUM_V)
) ;

-- -----------------------------------------------------------------------------
--       TABLE : VILLES_SOUHAITÉES
-- -----------------------------------------------------------------------------

CREATE TABLE VILLES_SOUHAITEES
(
	NUM_V int4 NOT NULL  ,
	NUM_S int4 NOT NULL  ,   
		CONSTRAINT PK_VILLES_SOUHAITEES PRIMARY KEY (NUM_V, NUM_S)
) ;

-- -----------------------------------------------------------------------------
--       INDEX DE LA TABLE VILLES_SOUHAITÉES
-- -----------------------------------------------------------------------------

CREATE  INDEX I_FK_VILLES_SOUHAITEES_VILLES ON VILLES_SOUHAITEES (NUM_V) ;
CREATE  INDEX I_FK_VILLES_SOUHAITEES_SOUHAIT ON VILLES_SOUHAITEES (NUM_S) ;

-- -----------------------------------------------------------------------------
--       CREATION DES REFERENCES DE TABLE
-- -----------------------------------------------------------------------------
ALTER TABLE VISITES ADD 
     CONSTRAINT FK_VISITES_SOUHAITS
          FOREIGN KEY (NUM_S)
               REFERENCES SOUHAITS (NUM_S);

ALTER TABLE VISITES ADD 
     CONSTRAINT FK_VISITES_BIENS
          FOREIGN KEY (NUM_B)
               REFERENCES BIENS (NUM_B);

ALTER TABLE BIENS ADD 
     CONSTRAINT FK_BIENS_VILLES
          FOREIGN KEY (NUM_V)
               REFERENCES VILLES (NUM_V);

ALTER TABLE BIENS ADD 
     CONSTRAINT FK_BIENS_CLIENTS
          FOREIGN KEY (NUM_C)
               REFERENCES CLIENTS (NUM_C);

ALTER TABLE SOUHAITS ADD 
     CONSTRAINT FK_SOUHAITS_CLIENTS
          FOREIGN KEY (NUM_C)
               REFERENCES CLIENTS (NUM_C);

ALTER TABLE CLIENTS ADD 
     CONSTRAINT FK_CLIENTS_VILLES
          FOREIGN KEY (NUM_V)
               REFERENCES VILLES (NUM_V);

ALTER TABLE CLIENTS ADD 
     CONSTRAINT FK_CLIENTS_AGENTS
          FOREIGN KEY (NUM_A)
               REFERENCES AGENTS (NUM_A);

ALTER TABLE VILLES_SOUHAITEES ADD 
     CONSTRAINT FK_VILLES_SOUHAITEES_VILLES
          FOREIGN KEY (NUM_V)
               REFERENCES VILLES (NUM_V);

ALTER TABLE VILLES_SOUHAITEES ADD 
     CONSTRAINT FK_VILLES_SOUHAITEES_SOUHAITS
          FOREIGN KEY (NUM_S)
               REFERENCES SOUHAITS (NUM_S);

-- -----------------------------------------------------------------------------
--                FIN DE GENERATION
-- -----------------------------------------------------------------------------
