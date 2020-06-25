<?
   echo "<form name=\"formbuscarcons\" method=\"post\" action=\"index.php?opcion=buscar_consulta\" class=\"formone\">";
        echo "<ul><li>Contenido</li></ul>";
        echo "<input name=\"x_buscar\" type=\"text\" size=\"115\" class=\"ingresotx\">";
        echo "<ul><li>Cliente</li></ul>";
        echo "<select name=\"c_clisel\" >";

         echo "<option value=\"-1\" selected\">Todos</option>";
         $SQL = " select Idresto,NombreRest ";
         $SQL = $SQL . " from r_resto ";
	     $SQL = $SQL . " Order by NombreRest";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idresto = $row["Idresto"];
      		    $resto = $row["NombreRest"];
    	   		if ($idresto == $clisel ) {
           		    echo "<option value=".$idresto." selected>".$resto."</option>";
           		} else {
                   echo "<option value=".$idresto." >".$resto."</option>";
           		}
           	}
         }
         echo "</select>";

         echo "<ul><li>Estado</li></ul>";
         echo "<ul>";
         echo "<li>";
         echo "<input name=\"x_estado\" type=\"radio\" class=\"check\" value=\"P\" checked>";
         echo "<label>Pendientes</label>";
         echo "</li>";
         echo "<li>";
         echo "<input name=\"x_estado\" type=\"radio\" class=\"check\" value=\"F\">";
         echo "<label>Finalizadas</label>";
         echo "</li>";
         echo "<li>";
         echo "<input name=\"x_estado\" type=\"radio\" class=\"check\" value=\"T\">";
         echo "<label>Todas</label>";
         echo "</li>";
         echo "</ul>";

         echo "<input type=\"submit\" class=\"input\" value=\"Buscar\">";
         echo "<input type=\"hidden\" name=\"modoOp\" value=\"buscar_ultima\">";
         echo "</form>";


?>

