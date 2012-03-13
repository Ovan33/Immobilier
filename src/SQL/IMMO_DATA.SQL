-- -----------------------------------------------------------------------------
--             Génération d'une base de données pour
--                           PostgreSQL
--                        (12/3/2012 14:00:20)
-- -----------------------------------------------------------------------------
--      Nom de la base : IMMO
--      Projet : AgImmo
--      Auteur : Gilles Coulais
-- 		Testé avec succès sous
--		- PostGreSQL
--
--		Ce script insère les données dans la base. Il doit être exécuté après 
--		le script IMMO_.sql
-- -----------------------------------------------------------------------------

-- -----------------------------------------------------------------------------
--       Insertion de données
-- -----------------------------------------------------------------------------
DELETE FROM AGENTS ;
INSERT INTO AGENTS VALUES(default, 'GEORGES') ;
INSERT INTO AGENTS VALUES(default, 'PAUL') ;
INSERT INTO AGENTS VALUES(default, 'RINGO') ;
INSERT INTO AGENTS VALUES(default, 'JOHN') ;

DELETE FROM VILLES ;
INSERT INTO VILLES VALUES(default, 'CADAUJAC', 33140) ;
INSERT INTO VILLES VALUES(default, 'VILLENAVE-D''ORNON', 33140) ;
INSERT INTO VILLES VALUES(default, 'BORDEAUX', 33000) ;
INSERT INTO VILLES VALUES(default, 'LA ROCHELLE', 17000) ;

DELETE FROM CLIENTS ;
--       Clients affectés à un agent
INSERT INTO CLIENTS VALUES(default, 1,1,'BOB MORANE','67 RUE DES ALOUETTES','0556525267') ;
INSERT INTO CLIENTS VALUES(default, 2,1,'JEAN VALJEAN','90 RUE DU TRUC','0556525292') ;
INSERT INTO CLIENTS VALUES(default, 2,2,'DIANE DE MONSTRUC','90 AVENUE DU MACHIN','0627985292') ;
--       Clients non affectés à un agent
INSERT INTO CLIENTS VALUES(default, 1,NULL,'JOHN PAUL LE PERSE','12 IMPASSE DU N''IMPORTE QUOI','0556675267') ;
INSERT INTO CLIENTS VALUES(default, 1,NULL,'JEANNETTE LA BELETTE','256 RUE DU HA','0556664467') ;

DELETE FROM SOUHAITS ;
INSERT INTO SOUHAITS VALUES(default, 3, '250000', '200', '600') ;
INSERT INTO SOUHAITS VALUES(default, 1, '500000', '300', '3000') ;
INSERT INTO SOUHAITS VALUES(default, 2, '200000', '100', '200') ;

DELETE FROM VILLES_SOUHAITEES ;
INSERT INTO VILLES_SOUHAITEES VALUES(1,1) ;
INSERT INTO VILLES_SOUHAITEES VALUES(4,2) ;
INSERT INTO VILLES_SOUHAITEES VALUES(3,3) ;

DELETE FROM BIENS ;
INSERT INTO BIENS VALUES(default,1,4,'250000','22/01/2012','200','3000') ;
INSERT INTO BIENS VALUES(default,1,4,'150000','23/01/2012','75','200') ;
INSERT INTO BIENS VALUES(default,2,4,'450000','23/12/2011','150','900') ;
INSERT INTO BIENS VALUES(default,2,5,'350000','17/11/2011','200','1100') ;

DELETE FROM VISITES ;
INSERT INTO VISITES VALUES(default, 1,1,'11/01/2012','18:00:00') ;
INSERT INTO VISITES VALUES(default, 1,1,'17/03/2012','10:00:00') ;
INSERT INTO VISITES VALUES(default, 2,3,'14/03/2012','16:30:00') ;

