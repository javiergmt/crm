<table summary="Consultas">


       <?

        $idcanal=1;
        $x_email='';
        echo "<form name=\"formnuevaconsulta\" method=\"post\" action=\"index.php?opcion=grabar_nueva_consulta\" class=\"formone\">";


        echo "<ul><li>Cliente&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_idresto\" >";

         $SQL = "select Idresto,NombreRest ";
         $SQL = $SQL . " from r_resto ";
	     $SQL = $SQL . " Order by NombreRest";
         $retid = mysql_query($SQL, $cid);
	     if (!$retid) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid)) {
				$idresto = $row["Idresto"];
      		    $resto = $row["NombreRest"];
                echo "<option value=".$idresto." >".$resto."</option>";
            }
         }
        echo "</select>";
        echo "</li></ul>";
        
        echo "<ul><li>Canal&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_canal\" style=\"BACKGROUND-COLOR: #FFFFFF; FONT-FAMILY:arial; FONT-SIZE: 10px\" class=\"campos3\">";

        $SQL = " select * ";
        $SQL = $SQL . " from r_canales";
        $SQL = $SQL . " Order by Descripcion";

        $retid = mysql_query($SQL, $cid);
        if (!$retid) { echo("Error en la consulta"); }
        else {
             while ($row = mysql_fetch_array($retid)) {
                   $idcanal = $row["IdCanal"];
                   $canal = $row["Descripcion"];
                   echo "<option value=$idcanal >".$canal."</option>";

             };
        };
        echo "</select>";
        echo "</li></ul>";
        
        echo "<ul><li>Asignada a: &nbsp;&nbsp;";
        echo "<select name=\"x_oper\" style=\"BACKGROUND-COLOR: #FFFFFF; FONT-FAMILY:arial; FONT-SIZE: 10px\" class=\"campos3\">";

        $SQL = " select * ";
        $SQL = $SQL . " from r_operador";
        $SQL = $SQL . " Order by IdOperador";

        $retid = mysql_query($SQL, $cid);
        if (!$retid) { echo("Error en la consulta"); }
        else {
             while ($row = mysql_fetch_array($retid)) {
                   $idoperador = $row["IdOperador"];
                   $operador = $row["Nombre"];
                   echo "<option value=$idoperador >".$operador."</option>";
             };
        };
        echo "</select>";
        echo "</li></ul>";

        
        echo "<ul><li>Detalle de la Consulta</li></ul>";
        echo "<textarea name=\"x_consulta\" rows=\"7\" wrap=\"PHYSICAL\" cols=\"60\"></textarea>";
        echo "<ul><li>Respuesta</li></ul>";
        echo "<textarea name=\"x_respuesta\" rows=\"7\" wrap=\"PHYSICAL\" cols=\"60\"></textarea>";

        echo "<ul><li>Estado</li></ul>";
        echo "<ul>";
        echo "<li>";
        echo "<input name=\"x_estado\" type=\"radio\" class=\"check\" value=\"P\" checked>";
        echo "<label>Pendiente</label>";
        echo "</li>";
        echo "<li>";
        echo "<input name=\"x_estado\" type=\"radio\" class=\"check\" value=\"F\">";
        echo "<label>Finalizada</label>";
        echo "</li>";
        echo "</ul>";

        echo "<ul><li>";
        echo "<a href=\"#\" onClick=\"javascript:pedirgrabarconsultanueva()\"><img src=\"images/boton_grabar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
        echo "</li></ul>";

        echo "</form>";
       ?>

</table>
