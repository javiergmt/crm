
<?
 echo "<form name=\"formbuscarequi\" method=\"post\" action=\"index.php?opcion=buscar_equipos\" class=\"formone\">";
        echo "<ul><li>Contenido</li></ul>";
        echo "<input name=\"x_buscar\" type=\"text\" size=\"115\" class=\"ingresotx\">";

        echo "<ul><li>Estado</li></ul>";
        echo "<select name=\"x_estadosel\" >";

         echo "<option value=\"-1\" selected\">Todos</option>";
         $SQL = " select idestado,descrip ";
         $SQL = $SQL . " from e_estados ";
	     $SQL = $SQL . " Order by idestado";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idestado = $row["idestado"];
      		    $estado = $row["descrip"];
    	   		if ($idestado == $estadosel ) {
           		    echo "<option value=".$idestado." selected>".$estado."</option>";
           		} else {
                   echo "<option value=".$idestado." >".$estado."</option>";
           		}
           	}
         }
         echo "</select>";
         
         echo "<ul><li>Tipo</li></ul>";
         echo "<select name=\"x_tiposel\" >";

         echo "<option value=\"-1\" selected\">Todos</option>";
         $SQL = " select idtipo,descrip ";
         $SQL = $SQL . " from e_tipos ";
	     $SQL = $SQL . " Order by idtipo";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idtipo = $row["idtipo"];
      		    $tipo = $row["descrip"];
    	   		if ($idtipo == $tiposel ) {
           		    echo "<option value=".$idtipo." selected>".$tipo."</option>";
           		} else {
                   echo "<option value=".$idtipo." >".$tipo."</option>";
           		}
           	}
         }
         echo "</select>";

         echo "<input type=\"submit\" class=\"input\" value=\"Buscar\">";
         echo "<input type=\"hidden\" name=\"modoOp\" value=\"buscar_ultima\">";
         echo "</form>";
?>

