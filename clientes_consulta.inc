<?
echo "<form name=\"formclientes\" method=\"post\" action=\"index.php\" >";

echo "<table summary=\"Clientes\">";

  $SQL = " Select r.*,a.Descripcion as TipoAbono,g.Descripcion as Region from r_resto r";
  $SQL = $SQL . " left outer join r_abonos a on a.idAbono = r.Abono ";
  $SQL = $SQL . " left outer join r_regiones g on g.idRegion = r.IdRegion ";
  $SQL = $SQL . " where ( r.Activo <> 0 ) and ";
  $SQL = $SQL . " ( IdResto = ".$idresto." )";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;
    if ($row = mysql_fetch_array($retid)) {

        $nombrerest = $row["NombreRest"];
        $idabono = $row["Abono"];
		$abono = $row["TipoAbono"];
		$telefono = $row["TelefonoRest"];
		$direccion = $row["Direccion"];
		$localidad = $row["Localidad"];
        $provincia = $row["Provincia"];
        $region = $row["Region"];
        $claveuso = $row["Claveuso"];
        $clavemes = $row["ClaveMes"];
        $nombreclave = $row["NombreClave"];
        $user = $row["User"];
        $clave = $row["Clave"];
        $observacion = $row["Observacion"];
        $conexion = $row["Conexion"];
        $configuracion = $row["Configuracion"];
        $email = $row["Email"];
        $mapa = $row["mapa"];
        $version = $row["Version"];
        $factelec = $row["FactElec"];
        
        echo "<thead>";

        echo "<tr>";
        echo "<th colspan=\"2\" scope=\"row\">[ ".$idresto." ] ".$nombrerest."</th>";
        echo "</tr>";

        echo "</thead>";

        echo "<tfoot>";
        echo "<tr><th scope=\"row\"></th><td colspan=\"2\"></td></tr>";
        echo "</tfoot>";

        echo "<tbody>";
        

        
        echo "<tr>";
        echo "<th scope=\"row\" id=\"r100\">TIPO CLIENTE:</th>";
        echo "<th scope=\"row\" id=\"r100\">".$abono."</th>";
        echo "</tr>";
        
        echo "<tr class=\"odd\">";
        echo "<th scope=\"row\" id=\"r100\">CLAVE ABONO:</th>";
        if ( $idabono <> 7 ) {
        echo "<th scope=\"row\" id=\"r100\">".$claveuso." - ".$clavemes." ( ".$nombreclave." ) </th>";
        } else {
        echo "<th scope=\"row\" id=\"r100\"> </th>";
        }
        echo "</tr>";
        
        echo "<tr>";
        echo "<th scope=\"row\" id=\"r100\">VERSION MOD. VENTAS:</th>";
        echo "<th scope=\"row\" id=\"r100\">".$version." ";
        If ( $factelec == 1 ) {
           echo " - Tiene FACT. ELECTRONICA </th>";
        } else {
           echo "</th>";
        }
        echo "</tr>";
        
        echo "<tr class=\"odd\">";
        echo "<th scope=\"row\" id=\"r100\">DIRECCION:</th>";
        echo "<th scope=\"row\" id=\"r100\">".$direccion." ".$localidad.", ".$provincia."</th>";
        
        echo "<tr>";
        echo "<th scope=\"row\" id=\"r100\">TELEFONO:</th>";
        echo "<th scope=\"row\" id=\"r100\">".$telefono."</th>";
        echo "</tr>";
        
        echo "<tr class=\"odd\">";
        echo "<th scope=\"row\" id=\"r100\">ACCESO WEB:</th>";
        echo "<th scope=\"row\" id=\"r100\">Usr: ".$user." , Clave: ".$clave."</th>";

        echo "<tr>";
        echo "<th scope=\"row\" id=\"r100\">EMAIL:</th>";
        echo "<th scope=\"row\" id=\"r100\">".$email."</th>";
        echo "</tr>";

        echo "<tr class=\"pie\">";
        echo "<th colspan=\"2\" scope=\"row\">".$configuracion."</th>";
        echo "</tr>";

        echo "<tr class=\"pie\">";
        echo "<th colspan=\"2\" scope=\"row\">".$conexion."</th>";
        echo "</tr>";

        echo "<tr class=\"pie\">";
        echo "<th colspan=\"2\" scope=\"row\">".$observacion."</th>";
        echo "</tr>";



        echo "</tbody>";

     };
   };


   echo "<input type=\"hidden\" name=\"x_idresto\" value=$idresto>";
   echo "<input type=\"hidden\" name=\"x_user\" value=$user>";
   echo "<input type=\"hidden\" name=\"x_clave\" value=$clave>";
   echo "<input type=\"hidden\" name=\"x_email\" value=$email>";
   echo "<input type=\"hidden\" name=\"opcion\">";
   
   echo "<ul><li>";
   echo "<a href=\"#\" onClick=\"javascript:pedireditarcliente()\"><img src=\"images/boton_editar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "<a href=\"#\" onClick=\"javascript:pedirdesactcliente()\"><img src=\"images/boton_desactivar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "<a href=\"#\" onClick=\"javascript:pedirenviaremailcli()\"><img src=\"images/email.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";

   $plano = 'planos/FichaTecnica'.$idresto.'.pdf';
   if ( file_exists ( $plano ) ) {
   echo "<a href=\"planos\FichaTecnica$idresto.pdf\"><img src=\"images/boton_plano.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   }
   echo "</li></ul>";
   
   echo "<ul><li>";
   echo $mapa;
   echo "</li></ul>";

echo "</table>";

  /*
  $SQL = " Select * from r_telefonos c ";
  $SQL = $SQL . " where c.IdRest = ".$idresto;

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {

    $paso=1; $tit=1;
    While ($row = mysql_fetch_array($retid)) {
        $nombre = $row["Nombre"];
		$cargo = $row["Cargo"];
		$telefono = $row["Telefono"];
        $email = $row["email"];
        $id = $row["IdPersona"];

        if ( $tit==1 ) {
        echo "<br>";
        echo "<table >";
        echo "<thead>";
        echo "<tr>";
        echo "<th scope=\"col\">ID</th><th scope=\"col\">NOMBRE</th><th scope=\"col\">CARGO</th><th scope=\"col\">TELEFONO</th><th scope=\"col\">EMAIL</th>";
        echo "</tr>";
        echo "</thead>";
        echo "<tfoot>";
        echo "<tr><th scope=\"row\"></th><td colspan=\"5\"></td></tr>";
        echo "</tfoot>";
        echo "<tbody>";
        $tit=0;
        }

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

        echo "<th scope=\"row\" id=\"r100\">".$id."</th>";
        echo "<td>".$nombre."</td>";
        echo "<td>".$cargo."</td>";
        echo "<td>".$telefono."</td>";
        echo "<td>".$email."</td>";
        echo "</tr>";

     };
     echo "</tbody>";
     If ( $tit==0 ) {
     echo "<ul><li>";
     echo "<a href=\"#\" onClick=\"javascript:pedireditarcliente()\"><img src=\"images/boton_editar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
     echo "</li></ul>";
     };
     echo "</table>";
  };
  echo "<br>";
  */

  $SQL = " Select c.*, o.Nombre as Oper from r_consultas c ";
  $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
  $SQL = $SQL . " where c.IdResto = ".$idresto;
  $SQL = $SQL . " order by c.IdConsulta DESC ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {

    $paso=1; $tit=1;
    While ($row = mysql_fetch_array($retid)) {
        $idconsulta = $row["IdConsulta"];
		$fecha = $row["Fecha"];
		$hora = $row["Hora"];
        $consulta = $row["Consulta"];
        $oper = $row["Oper"];
        $respuesta = $row["Respuesta"];
        
        if ( $tit==1 ) {
        echo "<caption>Consultas / Tareas</caption>";
        echo "<br>";
        echo "<table>";
        echo "<thead>";
        echo "<tr>";
        echo "<th scope=\"col\">NRO</th><th scope=\"col\">FECHA</th><th scope=\"col\">RESP</th><th scope=\"col\">CONSULTA</th><th scope=\"col\">RESPUESTA</th>";
        echo "</tr>";
        echo "</thead>";
        echo "<tfoot>";
        echo "<tr><th scope=\"row\"></th><td colspan=\"5\"></td></tr>";
        echo "</tfoot>";
        echo "<tbody>";
        $tit=0;
        }

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

        echo "<th scope=\"row\" id=\"r100\">".$idconsulta."</th>";
        echo "<td>".$fecha." - ".$hora."</td>";
        echo "<td>".$oper."</td>";
        echo "<td>".$consulta."</td>";
        echo "<td>".$respuesta."</td>";
        echo "</tr>";

     };
     echo "</tbody>";
     echo "</table>";
   };


echo "</form>";


?>
