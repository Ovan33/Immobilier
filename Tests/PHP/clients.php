<html>
	<head>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<title>Clients</title>
	</head>

	<body>
		<

		<!-- Création de la connection et des variables -->

		<?php
			$dbHost = "localhost"; 	// En principe rien à modifier
			$dbName = "BASE";		// le nom de la base
			$dbUser = "USER";	// le user PostGreSQL à utiliser
			$dbPass = "PASS";	// le mot de passe du user
			$dbQuery =  "	select nom_c, adresse_c, tel_c, nom_v, code_postal_v, prenom_a from CLIENTS
							INNER JOIN VILLES on villes.num_v=clients.num_v
							LEFT OUTER JOIN AGENTS on agents.num_a=clients.num_a ;"; // la requête que vous souhaitez exécuter.
			$connectDB 		= pg_connect("host=$dbHost dbname=$dbName user=$dbUser password=$dbPass");			
			if (!$connectDB) {
				print("Connection failed.");
				exit;
			} 
			$result 	= pg_exec($connectDB,$dbQuery);
			$numrows 	= pg_num_rows($result);
		?>
			
		<table border="1">
			<!-- Tout ce qui se trouve sous cette ligne est à adapter en fonction de votre requête-->

			<!-- Les noms de colonnes du tableau à afficher -->
			<tr>
				<th>Nom</th>
				<th>Adresse</th>
				<th>Téléphone</th>
				<th>Ville</th>
				<th>Code postal</th>
				<th>Agent</th>
			</tr>
			<?

				for($ri = 0; $ri < $numrows; $ri++) {
					echo "<tr>\n";
						$row = pg_fetch_array($result, $ri);
						/* Insérer ci-dessous les noms de colonnes tels que fournis par la base */
						echo " <td>", $row["nom_c"], "</td>
								<td>", $row["adresse_c"], "</td>
								<td>", $row["tel_c"], "</td>
								<td>", $row["nom_v"], "</td>
								<td>", $row["code_postal_v"], "</td>
								<td>", $row["prenom_a"], "</td>
						</tr>
					";
				}
				pg_close($connectDB);
				?>
		</table>
	</body>
</html>
