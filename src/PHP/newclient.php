<html>
	<head>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<title>Ma page d'accueil</title>
	</head>
	<body>
		<?php		
			// Création de la connection à la base
			$connectDB 		= connectionBase();			
			if (!$connectDB) {
				print("Connection failed.");
				exit;
			}
			$req_Villes = "select * from villes ;";
			$res_Villes = pg_exec($connectDB,$req_Villes);

			// Saisie des informations
			echo '
				<h3>Toutes les informations sont obligatoires</h3>
				<form name="nouveauClient" method="post" action="newclient.php">
					Nom : 			<input type="text" name="nom"/> <br/>
					Adresse : 		<input type="text" name="adresse"/><br/>
					Code postal : 	<input type="text" name="cp"/>
					<input type="submit" name="vilCherch" value="Chercher les villes"/><br/>
					';
				if(isset($_POST["vilCherch"]))
				{
					$cp_c=$_POST['cp'];
					echo "Appui chercher villes $cp_c";
/*
					$villesQuery="select num_v, nom_v from villes where code_postal_v='$cp_c' ORDER by nom_v ;";
					$listVilles	= pg_exec($connectDB,$villesQuery);
					$nbVilles 	= pg_num_rows($listVilles);

					echo "nbVilles $nbVilles";
					* */
				};

				// echo "Ville : <select name=\"ville\"> ";
				echo '<option value="-1">Choisissez la ville</option>';
				for($li=0; $li < $nbVilles; $li++) 
				// while($row = pg_fetch_assoc($villesQuery))
				{
					$row = pg_fetch_array($listVilles, $li);
					// echo("<option value="+$row["num_v"]+">"+$row["nom_v"]+"</option>");
					echo '<option value="'.$row["num_v"].'">'.$row["nom_v"].'</option>';
				} ;
			
			echo '	</select><br/>
					Téléphone : 	<input type="text" name="tel"/><br/>
					<input type="submit" name="valider" value="Valider"/>
				</form>';
		
		?>
		<!-- Traitement après clic sur le bouton ok-->
		<?php
			if(isset($_POST['valider'])){
				
				// Création des variables PHP à partir des infos du formulaire
				$nom_c = $_POST['nom'];
				$adresse_c=$_POST['adresse'];
				// $ville_c=$POST['ville'];
				$tel_c=$_POST['tel'];
								
				// Création et exécution de la requête
				// $villeQuery =  ""; 
				
				// $result 	= pg_exec($connectDB,$dbQuery);
				
				echo $nom_c," ",$adresse_c," ",$tel_c," ",$nbVilles;
			}
			pg_close($connectDB);
		?>

		<!-- Fonctions PHP -->
		<?php
			// Adapter les valeurs ci-dessous
			function connectionBase($dbHost="localhost",$dbName="immo", $dbUser="gcoulais", $dbPass="gcoulais") 
			{
				return pg_pconnect("host=$dbHost dbname=$dbName user=$dbUser password=$dbPass");
			}
		?>
	</body>
</html>
