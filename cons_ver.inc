
<table summary="Consultas">
 <?
         switch ( trim($estado) ) {
         case "P": {
              echo "<caption>Pendientes</caption>";
         };
         break;
         case "F": {
              echo "<caption>Finalizadas</caption>";
         };
         break;
         case "T": {
              echo "<caption>Todas</caption>";
         };
         break;

         };
?>

<thead>
<tr>
<th scope="col">NRO</th><th scope="col">CONSULTA</th><th scope="col">RESTO</th><th scope="col">FECHA</th><th scope="col">CANAL</th><th scope="col">RESP</th>
</tr>
</thead>
<tfoot>
<tr><th scope="row"></th><td colspan="5"></td></tr>
</tfoot>

<tbody>
<?
echo "<form name=\"formconsultas\" method=\"post\" action=\"index.php?opcion=ampliar_cons\" >";

  if ($buscar <> "" ) {
  $SQL = " Select c.*,r.NombreRest as Resto, o.Nombre as Oper , k.Descripcion as Canal from r_consultas c ";
  $SQL = $SQL . " left outer join r_resto r on r.Idresto = c.IdResto ";
  $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
  $SQL = $SQL . " inner join r_canales k on k.IdCanal = c.IdCanal ";
  $SQL = $SQL . " and upper(c.Consulta) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$clisel." = -1) OR (".$clisel." = r.Idresto) )";
  $SQL = $SQL . " and ((Estado = '".$estado."') or ('".$estado."'='T'))";
  $SQL = $SQL . " order by c.IdCOnsulta DESC ";

  } else {

  $SQL = " Select c.*,r.NombreRest as Resto,o.Nombre as Oper, k.Descripcion as Canal from r_consultas c ";
  $SQL = $SQL . " left outer join r_resto r on r.Idresto = c.IdResto ";
  $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
  $SQL = $SQL . " inner join r_canales k on k.IdCanal = c.IdCanal ";
  $SQL = $SQL . " and ((".$clisel." = -1) OR (".$clisel." = r.Idresto) )";
  $SQL = $SQL . " and ((Estado = '".$estado."') or ('".$estado."'='T'))";
  $SQL = $SQL . " order by c.IdConsulta DESC";

  }
  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;
    While ($row = mysql_fetch_array($retid)) {
        $idresto = $row["IdResto"];
        $idconsulta = $row["IdConsulta"];
		$nombrerest = $row["Resto"];
		$fecha = $row["Fecha"];
		$hora = $row["Hora"];
        $estado = $row["Estado"];
        $consulta = $row["Consulta"];
        $oper = $row["Oper"];
        $respuesta = $row["Respuesta"];
        $canal = $row["Canal"];
        
        if ( $respuesta == '' ) { $respuesta = 'SIN RESPUESTA'; };

        if ($paso==1) {
			$paso=2;
		} else {
        	$paso=1;
        }

        if ($paso==1) {
        echo "<tr>";
	    } else {
        echo "<tr class=\"odd\">";
        };

        //echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=ampliar_cons&idresto=$idresto&idampliar=$idconsulta\" onClick=\"javascript:pedirgrabarconsulta()\">".$idconsulta."</a></th>";
        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=ampliar_cons&idresto=$idresto&idampliar=$idconsulta\"  title='".$respuesta."'>".$idconsulta."</a></th>";

        echo "<td>".$consulta."</td>";
        echo "<td>".$nombrerest."</td>";
        echo "<td>".$fecha." ".$hora."</td>";
        echo "<td>".$canal."</td>";
        echo "<td>".$oper."</td>";
        echo "</tr>";

     };
   };

   echo "</form>";


echo "</tbody>";
echo "<ul><li>";
echo "<a href=\"index.php?opcion=nueva_consulta\"><img src=\"images/boton_nueva.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
echo "<a href=\"index.php?opcion=notif_consulta\"><img src=\"images/email.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
echo "</li></ul>";
echo "</table>";
?>

