
<?
  echo "<form name=\"formbuscarcli\" method=\"post\" action=\"index.php?opcion=buscar_clientes\" class=\"formone\">";
        echo "<ul><li>Contenido</li></ul>";
        echo "<input name=\"x_buscar\" type=\"text\" size=\"115\" class=\"ingresotx\">";
        echo "<ul><li>Zona</li></ul>";
        echo "<select name=\"x_zonasel\" >";

         echo "<option value=\"-1\" selected\">Todas</option>";
         $SQL = " select IdRegion,Descripcion ";
         $SQL = $SQL . " from r_regiones ";
	     $SQL = $SQL . " Order by Descripcion";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idregion = $row["IdRegion"];
      		    $region = $row["Descripcion"];
    	   		if ($idregion == $zonasel ) {
           		    echo "<option value=".$idregion." selected>".$region."</option>";
           		} else {
                   echo "<option value=".$idregion." >".$region."</option>";
           		}
           	}
         }
         echo "</select>";

         echo "<ul><li>Abono</li></ul>";
         echo "<select name=\"x_abonosel\" >";

         echo "<option value=\"-1\" selected\">Todas</option>";
         $SQL = " select IdAbono,Descripcion ";
         $SQL = $SQL . " from r_abonos ";
	     $SQL = $SQL . " Order by Descripcion";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idabono = $row["IdAbono"];
      		    $abono = $row["Descripcion"];
    	   		if ($idabono == $abonosel ) {
           		    echo "<option value=".$idabono." selected>".$abono."</option>";
           		} else {
                   echo "<option value=".$idabono." >".$abono."</option>";
           		}
           	}
         }
         echo "</select>";

         echo "<input type=\"submit\" class=\"input\" value=\"Buscar\">";
         echo "<input type=\"hidden\" name=\"modoOp\" value=\"buscar_ultima\">";
         echo "</form>";
?>
