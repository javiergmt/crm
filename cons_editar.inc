<?
echo "<table summary=\"Consultas\">";

echo "<form name=\"formconsultas\" method=\"post\" action=\"index.php?opcion=grabar_consulta\" >";

  $SQL = " Select c.*,r.NombreRest as Resto,o.Nombre as Oper from r_consultas c ";
  $SQL = $SQL . " left outer join r_resto r on r.Idresto = c.IdResto ";
  $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
  $SQL = $SQL . " where IdConsulta = ".$idampliar;

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;
    if ($row = mysql_fetch_array($retid)) {
        $idresto = $row["IdResto"];
        $idconsulta = $row["IdConsulta"];
		$nombrerest = $row["Resto"];
		$fecha = $row["Fecha"];
		$hora = $row["Hora"];
        $estado = $row["Estado"];
        $consulta = $row["Consulta"];
        $oper = $row["Oper"];
        $respuesta = $row["Respuesta"];
        $idoper =  $row["IdOperador"];
        
        echo "<thead>";
        if ( $estado=='F' ) {
        echo "<img src=\"images/verde.gif\" width=\"12\" height=\"12\" border=\"0\">&nbsp;&nbsp;Finalizada";
        } else {
        echo "<img src=\"images/rojo.gif\" width=\"12\" height=\"12\" border=\"0\">&nbsp;&nbsp;Pendiente";
        }
        echo "<tr>";
        echo "<th scope=\"row\">".$nombrerest." - ".$fecha." ".$hora." - ".$oper."</th>";
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
                   if ($idoperador == $idoper) {
                     echo "<option value=$idoperador selected >".$operador."</option>";
                   } else {
                     echo "<option value=$idoperador >".$operador."</option>";
                   }
             };
        };
        echo "</select>";
        echo "</li></ul>";

         //echo "<input  name=\"x_oper\" value=$oper>";
        echo "</tr>";
        echo "</thead>";
        echo "<tfoot>";

        echo "</tfoot>";

        echo "<tbody>";
        echo "<tr>";
        echo "<th scope=\"row\" id=\"r100\">".$consulta."</th>";
        echo "</tr>";
        echo "<tr class=\"odd\">";
        echo "<th scope=\"row\" id=\"r100\">";
        if ( $estado == "P" ) {
        echo "<textarea name=\"x_respuesta\" rows=\"10\" wrap=\"PHYSICAL\" cols=\"60\">$respuesta</textarea>";
        } else {
        echo $respuesta;
        };
        //echo "<input name=\"x_buscar\" type=\"memo\" rows=\"5\" size=\"80\" class=\"ingresotx\" value=\".$respuesta.\">";
        echo "</th>";
        echo "</tr>";
        echo "</tbody>";

     };
   };
   if ( $estado == "P" ) {
   echo "<ul><li>";
   echo "<a href=\"#\" onClick=\"javascript:pedirgrabarconsulta()\"><img src=\"images/boton_grabar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "<a href=\"#\" onClick=\"javascript:pedirgrabarconsultafin()\"><img src=\"images/boton_finalizar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "</li></ul>";
   }
   echo "<input type=\"hidden\" name=\"x_idresto\" value=$idresto>";
   echo "<input type=\"hidden\" name=\"x_idconsulta\" value=$idconsulta>";
   echo "<input type=\"hidden\" name=\"x_consulta\" value='$consulta'>";
   echo "<input type=\"hidden\" name=\"x_fecha\" value=$fecha>";
   echo "<input type=\"hidden\" name=\"x_hora\" value=$hora>";
   //echo "<input type=\"hidden\" name=\"x_oper\" value=$oper>";
   echo "<input type=\"hidden\" name=\"x_finalizado\" value=\"F\">";
   //echo "<input type=\"hidden\" name=\"x_respuesta\" value=$respuesta>";

   echo "</form>";
echo "</table>";
 ?>
