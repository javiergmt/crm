<?
   if ( $opc == "buscar_equipos"  ) {
       $buscar="";
       $estadosel=-1;
       if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = strtoupper( $_REQUEST["x_buscar"]) ;
      };

      if (isSet($_REQUEST["x_estadosel"])) {
      	$estadosel = strtoupper( $_REQUEST["x_estadosel"]) ;
      };
      if (isSet($_REQUEST["x_tiposel"])) {
      	$tiposel = strtoupper( $_REQUEST["x_tiposel"]) ;
      };
      $seccion="equipos";
   };


   if ( $opc == "modif_equipo"  ) {
      if (isSet($_REQUEST["idequipo"])) {
      	$idequipo = $_REQUEST["idequipo"] ;
      };
      $seccion="equipos";
   };

   if ( $opc == "borrar_equipo"  ) {
      if (isSet($_REQUEST["x_idequipo"])) {
      	$idequipo = $_REQUEST["x_idequipo"] ;
      };
      $SQL = "Delete from e_propios ";
      $SQL = $SQL . " Where id = $idequipo";

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR al borrar el equipo\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"Equipo eliminado !!\");";
         echo "</script>";
      }
      $opc="buscar_equipos";
      $seccion="equipos";
   };


   if ( $opc == "grabar_equipo"  ) {
      if (isSet($_REQUEST["x_idequipo"])) {
      	$idequipo = $_REQUEST["x_idequipo"] ;
      };

      if (isSet($_REQUEST["x_identif"])) {
      	$identif = $_REQUEST["x_identif"] ;
      };

      if (isSet($_REQUEST["x_descrip"])) {
      	$descrip = $_REQUEST["x_descrip"] ;
      };

      if (isSet($_REQUEST["x_idestado"])) {
      	$idestado = $_REQUEST["x_idestado"] ;
      };

      if (isSet($_REQUEST["x_idtipo"])) {
      	$idtipo = $_REQUEST["x_idtipo"] ;
      };

      if (isSet($_REQUEST["x_fecha"])) {
      	$fecha = $_REQUEST["x_fecha"] ;
      };

      if (isSet($_REQUEST["x_destino"])) {
      	$destino = $_REQUEST["x_destino"] ;
      };

      if (isSet($_REQUEST["x_precio"])) {
      	$precio = $_REQUEST["x_precio"] ;
      };

      if (isSet($_REQUEST["x_origen"])) {
      	$origen = $_REQUEST["x_origen"] ;
      };
      
      if (isSet($_REQUEST["x_precious"])) {
      	$precious = $_REQUEST["x_precious"] ;
      };

      if ( $idequipo <> 0 ) {

      $SQL = "update e_propios set idestado = $idestado , idtipo = $idtipo , destino = '$destino' , precio = $precio,  precious = $precious,";
      $SQL = $SQL . " origen = '$origen' , fecha = '$fecha', identif = '$identif', descrip = '$descrip' ";
      $SQL = $SQL . " Where id = $idequipo";

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR al actualizar el equipo\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"Datos actualizados !!\");";
         echo "</script>";
      }
      
      } else {
      
      $SQL = "insert into e_propios (identif,descrip,idestado,idtipo,fecha,destino,precio,origen) ";
      $SQL = $SQL . " Values ( '$identif','$descrip',$idestado,$idtipo,'$fecha','$destino',$precio,'$origen')";
      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR al agregar el equipo\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"Equipo Agregado !!\");";
         echo "</script>";
      }
      
      }
      $opc="buscar_equipos";
      $seccion="equipos";
   };


?>
