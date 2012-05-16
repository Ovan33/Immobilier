/* Obtenir la liste des villes */
select * from villes ;

/* Obtenir la liste des clients avec le nom de la ville et le prénom de l'agent, 
pour les clients affectés à un agent */
select nom_c, adresse_c, tel_c, nom_v, code_postal_v, prenom_a from CLIENTS
INNER JOIN VILLES on villes.num_v=clients.num_v
LEFT OUTER JOIN AGENTS on agents.num_a=clients.num_a ;

/* Obtenir la liste des villes, triée par nom et filtrée par code postal */
select num_v, nom_v from villes where code_postal_v='$cp_c' ORDER by nom_v ;

/* Obtenir une ville particulière à partir de son nom et de son code postal */
/* Utilisée par la classe Ville */ 
select * from VILLES where NOM_V = '" + nom + "' and CODE_POSTAL_V = '" + codePostal + "';

/* Obtenir la liste des clients à partir de leur nom */
select CLIENTS.NUM_C, CLIENTS.nom_c, CLIENTS.adresse_c, CLIENTS.tel_c, VILLES.nom_v from CLIENTS
INNER JOIN VILLES on VILLES.NUM_V=CLIENTS.NUM_V
where CLIENTS.nom_c like 'DUP%'

/* Insertion client */
INSERT INTO clients(num_c, num_v, num_a, nom_c, adresse_c, tel_c) 
			VALUES (default, :num_v, :num_a, :nom_c, :adresse_c, :tel_c)
