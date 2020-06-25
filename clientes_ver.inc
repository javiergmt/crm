
<table summary="Clientes">
 <?
 //echo "<caption>Pendientes</caption>";
echo "<form name=\"formclientes\" method=\"post\" action=\"index.php?opcion=ampliar_cli\" >";


echo "<thead>";
echo "<tr>";
echo "<th scope=\"col\"><a href=\"index.php?opcion=ordenar_cli&x_orden=idResto&x_zonasel=$zonasel&x_abonosel=$abonosel\">NRO</a></th>";
echo "<th scope=\"col\"><a href=\"index.php?opcion=ordenar_cli&x_orden=NombreRest&x_zonasel=$zonasel&x_abonosel=$abonosel\">RESTO</a></th>";
echo "<th scope=\"col\"><a href=\"index.php?opcion=ordenar_cli&x_orden=Abono&x_zonasel=$zonasel&x_abonosel=$abonosel\">ABONO</a></th>";
echo "<th scope=\"col\">CLAVE</th>";
echo "<th scope=\"col\">TELEFONO</th>";
echo "<th scope=\"col\"><a href=\"index.php?opcion=ordenar_cli&x_orden=Localidad&x_zonasel=$zonasel&x_abonosel=$abonosel\">UBICACION</a></th>";
echo "</tr>";
echo "</thead>";

echo "<tfoot>";
echo "<tr><th scope=\"row\"></th><td colspan=\"5\"></td></tr>";
echo "</tfoot>";

echo "<tbody>";



  $SQL = " Select r.IdResto,r.NombreRest,a.Abreviacion as TipoAbono,r.TelefonoRest,r.Localidad,r.Provincia,r.Conexion,r.Abono,r.Clavemes,r.Claveuso,r.Impago, r.FactElec from r_resto r ";
  $SQL = $SQL . " left outer join r_abonos a on a.idAbono = r.Abono ";
  $SQL = $SQL . " where r.Activo <> 0";
  $SQL = $SQL . " and upper(r.NombreRest) like '%".$buscar."%'";

  $SQL = $SQL . " and ((".$zonasel." = -1) OR (".$zonasel." = r.IdRegion) )";
  $SQL = $SQL . " and ((".$abonosel." = -1) OR (".$abonosel." = r.Abono) )";
  $SQL = $SQL . " order by r.".$orden." ".$_SESSION['tipoorden'];
  
  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;
    While ($row = mysql_fetch_array($retid)) {
        $idresto = $row["IdResto"];
        $nombrerest = $row["NombreRest"];
		$abono = $row["TipoAbono"];
		$clavemes = $row["Clavemes"];
        $claveuso = $row["Claveuso"];
        $telefono = $row["TelefonoRest"];
		$localidad = $row["Localidad"];
        $provincia = $row["Provincia"];
        $impago = $row["Impago"];
        $factelec = $row["FactElec"];


        if ($paso==1) {
			$paso=2;
		} else {
        	$paso=1;
        }

        if ($impago==1 )
        { echo "<tr class=\"pie\">";
        } else {
          if ($paso==1) {
             echo "<tr>";
	       } else {
             echo "<tr class=\"odd\">";
           };
        };

        //echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=ampliar_cons&idresto=$idresto&idampliar=$idconsulta\" onClick=\"javascript:pedirgrabarconsulta()\">".$idconsulta."</a></th>";
        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=ampliar_cli&idresto=$idresto\">".$idresto."</a></th>";


        echo "<td>".$nombrerest."</td>";
        if ( $factelec == 1 ) {
          echo "<td>".$abono." (FE) </td>";
        } else {
          echo "<td>".$abono."</td>";
        }
        echo "<td>".substr($clavemes,0,3).'-'.$claveuso."</td>";
        echo "<td>".$telefono."</td>";
        echo "<td>".$localidad."</td>";
        echo "</tr>";

     };
   };
   echo "<input type=\"hidden\" name=\"x_idresto\" value=0>";
   echo "<input type=\"hidden\" name=\"opcion\">";

   echo "<ul><li>";
   echo "<a href=\"#\" onClick=\"javascript:pedireditarcliente()\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "</li></ul>";
   echo "</form>";
   ?>
   

</tbody>
</table>

