-- -----------------------------------------------------------------------------
--      Name of the database : IMMO
--      Project : Immobilier
--      Author : Gilles Coulais
--      last changed : 13/3/2012
-- 		Desgined for PostGreSQL 8.4.11
--		
--		This script creates the needed tables and associated constraints.
--		The database must exist before executing this script.
--
--		/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
-- 		 !	All existing data will be erased. You've been warned !
--		/!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
-- -----------------------------------------------------------------------------

-- -----------------------------------------------------------------------------
--       SUPPRESSION DES TABLES et CONTRAINTES EXISTANTES
-- -----------------------------------------------------------------------------
DROP INDEX i_fk_biens_clients CASCADE ;
DROP INDEX i_fk_biens_villes CASCADE ;
DROP INDEX i_fk_clients_agents CASCADE ;
DROP INDEX i_fk_clients_villes CASCADE ;
DROP INDEX i_fk_souhaits_clients CASCADE ;
DROP INDEX i_fk_villes_souhaitees_souhait CASCADE ;
DROP INDEX i_fk_villes_souhaitees_villes CASCADE ;
DROP INDEX i_fk_visites_biens CASCADE ;
DROP INDEX i_fk_visites_souhaits CASCADE ;

ALTER TABLE villes_souhaitees DROP CONSTRAINT pk_villes_souhaitees CASCADE ;
ALTER TABLE biens DROP CONSTRAINT pk_biens CASCADE ;
ALTER TABLE clients DROP CONSTRAINT pk_clients CASCADE ;
ALTER TABLE souhaits DROP CONSTRAINT pk_souhaits CASCADE ;
ALTER TABLE villes DROP CONSTRAINT pk_villes CASCADE ;
ALTER TABLE visites DROP CONSTRAINT pk_visites CASCADE ;

DROP TABLE visites CASCADE ;
DROP TABLE clients CASCADE ;
DROP TABLE biens CASCADE ;
DROP TABLE agents CASCADE ;
DROP TABLE souhaits CASCADE ;
DROP TABLE villes CASCADE ;
DROP TABLE villes_SOUHAITEES CASCADE ;

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
	NUM_S integer NOT NULL  ,
	NUM_B integer NOT NULL  ,
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
	NUM_V integer NOT NULL  ,
	NUM_C integer NOT NULL  ,
	PRIX_VENTE_B integer NOT NULL  ,
	DATE_MISE_EN_VENTE_B date NOT NULL  ,
	SURFACE_HAB_B integer NOT NULL  ,
	SURFACE_JARDIN_B integer NOT NULL ,   
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
	NUM_C integer NOT NULL  ,
	BUDGET_MAX_S integer NULL  ,
	SURFACE_HAB_MIN_S integer NULL  ,
	SURFACE_JARDIN_MIN_S integer NULL  ,
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
	NUM_V integer NOT NULL  ,
	NUM_A integer NULL  ,
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
	NUM_V integer NOT NULL  ,
	NUM_S integer NOT NULL  ,   
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


----------------------------------
select clients.num_c, count(biens.num_b) as NbBiens
from clients
left outer join biens on clients.num_c=biens.num_c
where clients.nom_c like 'DUP%'
group by clients.num_c

select 	CLIENTS.NUM_C, 
	CLIENTS.nom_c, 
	CLIENTS.adresse_c, 
	CLIENTS.tel_c, 
	VILLES.nom_v, 
	VILLES.code_postal_v, 
	(select count(BIENS.num_b) from Biens where biens.num_c=clients.num_c) as NbBiens,
	(select count(SOUHAITS.num_s) from Souhaits where souhaits.num_c=clients.num_c) as NbSouhaits
from CLIENTS 
INNER JOIN VILLES on VILLES.NUM_V=CLIENTS.NUM_V
left outer JOIN BIENS on BIENS.num_c=CLIENTS.num_c
left outer JOIN SOUHAITS on SOUHAITS.num_c=CLIENTS.num_c
where CLIENTS.num_c=4
group by clients.num_c, clients.nom_c, clients.adresse_c,clients.tel_c, villes.nom_v,villes.code_postal_v
order by clients.num_c

select * from biens
order by num_c

select * from souhaits
where num_c=3
order by num_c
