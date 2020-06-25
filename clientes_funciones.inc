<?

if ( $opc == "buscar_clientes"  ) {

     $buscar="";
     $abonosel=-1;
     $zonasel=-1;
     if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = $_REQUEST["x_buscar"] ;
      };
      if (isSet($_REQUEST["x_abonosel"])) {
      	$abonosel = $_REQUEST["x_abonosel"] ;
      };
      if (isSet($_REQUEST["x_zonasel"])) {
      	$zonasel = $_REQUEST["x_zonasel"] ;
      };
    $seccion="clientes";
};

if ( $opc == "ordenar_cli"  ) {
    if (isSet($_REQUEST["x_orden"])) {
      	$orden = $_REQUEST["x_orden"] ;
    };
    
    if( $orden == 'idResto' ) {
       if ( $_SESSION['tipoorden'] == 'DESC' ) {
           $_SESSION['tipoorden'] = '';
       } else {
           $_SESSION['tipoorden'] = 'DESC';
       };
    };

    if (isSet($_REQUEST["x_abonosel"])) {
      	$abonosel = $_REQUEST["x_abonosel"] ;
    };
      if (isSet($_REQUEST["x_zonasel"])) {
      	$zonasel = $_REQUEST["x_zonasel"] ;
    };

    $opc="buscar_clientes";
    $seccion="clientes";
};

if ( $opc == "ampliar_cli"  ) {
      if (isSet($_REQUEST["idresto"])) {
      	$idresto = $_REQUEST["idresto"] ;
      };
      $seccion="clientes";
};

if ( $opc == "editar_cli"  ) {
      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };
      $seccion="clientes";
};

if ( $opc == "grabarcli"  ) {
      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };

      if (isSet($_REQUEST["x_nombrerest"])) {
      	$nombrerest = $_REQUEST["x_nombrerest"] ;
      };
      
      if (isSet($_REQUEST["x_abono"])) {
      	$abono = $_REQUEST["x_abono"] ;
      };

      if (isSet($_REQUEST["x_direccion"])) {
      	$direccion = $_REQUEST["x_direccion"] ;
      };

      if (isSet($_REQUEST["x_localidad"])) {
      	$localidad = $_REQUEST["x_localidad"] ;
      };

      if (isSet($_REQUEST["x_provincia"])) {
      	$provincia = $_REQUEST["x_provincia"] ;
      };

      if (isSet($_REQUEST["x_importe"])) {
      	$importe = $_REQUEST["x_importe"] ;
      };

      if (isSet($_REQUEST["x_region"])) {
      	$idregion = $_REQUEST["x_region"] ;
      };

      /*
      if (isSet($_REQUEST["x_idsoporte"])) {
      	$idsoporte = $_REQUEST["x_idsoporte"] ;
      };
      */
      
      if (isSet($_REQUEST["x_responsable"])) {
      	$responsable = $_REQUEST["x_responsable"] ;
      };
      
      if (isSet($_REQUEST["x_telefonoresp"])) {
      	$telefonoresp = $_REQUEST["x_telefonoresp"] ;
      };
      
      if (isSet($_REQUEST["x_telefonorest"])) {
      	$telefonorest = $_REQUEST["x_telefonorest"] ;
      };

      if (isSet($_REQUEST["x_email"])) {
      	$email = $_REQUEST["x_email"] ;
      };

      if (isSet($_REQUEST["x_user"])) {
      	$user = $_REQUEST["x_user"] ;
      };

      if (isSet($_REQUEST["x_clave"])) {
      	$clave = $_REQUEST["x_clave"] ;
      };

      if (isSet($_REQUEST["x_nombreclave"])) {
      	$nombreclave = $_REQUEST["x_nombreclave"] ;
      };
      
      if (isSet($_REQUEST["x_claveuso"])) {
      	$claveuso = $_REQUEST["x_claveuso"] ;
      };
      
      if (isSet($_REQUEST["x_clavemes"])) {
      	$clavemes = $_REQUEST["x_clavemes"] ;
      };
      
      /*
      if (isSet($_REQUEST["claveobs"])) {
      	$claveobs = $_REQUEST["claveobs"] ;
      };
     */
     
      if (isSet($_REQUEST["x_observacion"])) {
      	$observacion = $_REQUEST["x_observacion"] ;
      };

      if (isSet($_REQUEST["x_configuracion"])) {
      	$configuracion = $_REQUEST["x_configuracion"] ;
      };

      if (isSet($_REQUEST["x_conexion"])) {
      	$conexion = $_REQUEST["x_conexion"] ;
      };

       if (isSet($_REQUEST["x_encargado"])) {
      	$encargado = $_REQUEST["x_encargado"] ;
      };


      if (isSet($_REQUEST["x_prioridad"])) {
      	$prioridad = $_REQUEST["x_prioridad"] ;
      };
      
      if (isSet($_REQUEST["x_comentario"])) {
      	$comentario = $_REQUEST["x_comentario"] ;
      };

      if (isSet($_REQUEST["x_orden"])) {
      	$orden = $_REQUEST["x_orden"] ;
      };
      
      if (isSet($_REQUEST["x_mapa"])) {
      	$mapa = $_REQUEST["x_mapa"] ;
      };


      if (isSet($_REQUEST["x_version"])) {
      	$version = $_REQUEST["x_version"] ;
      };
      
      if (isSet($_REQUEST["x_factelec"])) {
      	$factelec = $_REQUEST["x_factelec"] ;
      	$fe = 1;
      } else {
        $factelec = 'off'; $fe = 0 ;
      }


      if ( $idresto <> 0 ) {
      $SQL = "update r_resto set NombreRest = '$nombrerest' , Abono = '$abono' , Direccion = '$direccion' , Localidad = '$localidad', ";
      $SQL = $SQL . " Provincia = '$provincia' , Importe = $importe , IdRegion = $idregion , TelefonoResp = '$telefonoresp' , ";
      $SQL = $SQL . " TelefonoRest = '$telefonorest' , NombreClave = '$nombreclave' , User = '$user' , Clave = '$clave' , ";
      $SQL = $SQL . " Email = '$email' , Observacion = '$observacion' , Conexion = '$conexion', Configuracion = '$configuracion' , ";
      $SQL = $SQL . " Claveuso = '$claveuso' , Encargado = '$encargado' , Responsable = '$responsable' , ";
      $SQL = $SQL . " ClaveMes = '$clavemes' , Comentario = '$comentario' , Prioridad = $prioridad , Orden = $orden , mapa = '$mapa' , ";
      $SQL = $SQL . " Version = '$version' , FactElec = $fe";
      $SQL = $SQL . " Where idresto = $idresto";

      //echo $SQL;
      //echo "<br>";

      $retid = mysql_query($SQL, $cid);
	  if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR en la modificacion del Cliente\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"El Cliente fue modificado !!\");";
         echo "</script>";
      }
      $opc="editar_cli";
      $seccion="clientes";
      } else {
      
      $SQL = "Select Max(idresto) as ultimo from r_resto ";

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo("Error en la consulta");
      } else {
       if ($row = mysql_fetch_array($retid)) {
          $ultcliente=$row["ultimo"]+1;
          //echo "ultimo: "+$ultcliente;
          //echo "<br>";
          }
      }

      $SQL = "insert into r_resto (IdResto,NombreRest,User,Clave,Direccion,Localidad,Provincia,Pais,TelefonoRest,Encargado,Responsable, ";
      $SQL = $SQL . " RazonSocial,TipoIva,Cuit,Abono,TelefonoResp,Email,Ref_nombre,Ref_contacto,Ref_Telefono,PaginaWeb,Configuracion, ";
      $SQL = $SQL . " IdSoporte,Activo,IdRegion,Comentario,Prioridad,Orden,Importe,Observacion,NombreClave,Conexion,Claveuso,ClaveMes,ClaveObs,mapa,Version) ";
      $SQL = $SQL . " Values ( $ultcliente,'$nombrerest','$user','$clave','$direccion','$localidad','$provincia','ARGENTINA',";
      $SQL = $SQL . " '$telefonorest','$encargado','$responsable','','','',$abono,'$telefonoresp','$email','','','','','$configuracion',";
      $SQL = $SQL . " 0,1,$idregion,'$comentario',$prioridad,$orden,0,'$observacion','$nombreclave','$conexion','$claveuso','$clavemes','','$mapa','$version')";

      //echo $SQL;
      //echo "<br>";
      
       $retid = mysql_query($SQL, $cid);
	  if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR en alta del Cliente\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"El Cliente fue agregado !!\");";
         echo "</script>";
      }

      $buscar="";
      $abonosel=-1;
      $zonasel=-1;
      $orden = "idResto";
      $opc="buscar_clientes";
      $seccion="clientes";

      }
      
};
   
if ( $opc == "desactivar_cli"  ) {

     $buscar="";
     $abonosel=-1;
     $zonasel=-1;

      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };
      $SQL = "update r_resto set Activo = 0 ";
      $SQL = $SQL . "Where idresto = $idresto";

      //echo $SQL;
      //echo "<br>";

      $retid = mysql_query($SQL, $cid);
	  if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR en la modificacion del Cliente\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"El Cliente fue desactivado !!\");";
         echo "</script>";
      }
      $opc="buscar_clientes";
      $seccion="clientes";
};


   
if ($opc=="nuevocliente" ) {
      $SQL = "Select Max(idresto) as ultimo from r_resto ";

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo("Error en la consulta");
      } else {
       if ($row = mysql_fetch_array($retid)) {
          $ultcliente=$row["ultimo"]+1;
          echo "ultimo: "+$ultcliente;
          echo "<br>";
          }
     };

   };

   if ($opc=="agregarcli" ) {

      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };
      if (isSet($_REQUEST["x_nombrerest"])) {
      	$nombrerest = strtoupper( $_REQUEST["x_nombrerest"]) ;
      };
      if (isSet($_REQUEST["x_nombreclave"])) {
      	$nombreclave = strtoupper( $_REQUEST["x_nombreclave"]) ;
      };
      if (isSet($_REQUEST["x_usuario"])) {
      	$usuario = strtoupper( $_REQUEST["x_usuario"]) ;
      };
      if (isSet($_REQUEST["x_clave"])) {
      	$clave = strtoupper( $_REQUEST["x_clave"]) ;
      };
      if (isSet($_REQUEST["x_direccion"])) {
      	$direccion = strtoupper( $_REQUEST["x_direccion"]) ;
      };
      if (isSet($_REQUEST["x_localidad"])) {
      	$localidad = strtoupper( $_REQUEST["x_localidad"]) ;
      };
      if (isSet($_REQUEST["x_provincia"])) {
      	$provincia = strtoupper( $_REQUEST["x_provincia"]) ;
      };
       if (isSet($_REQUEST["x_idregion"])) {
      	$idregion = $_REQUEST["x_idregion"] ;
      };
      if (isSet($_REQUEST["x_prioridad"])) {
      	$prioridad =  $_REQUEST["x_prioridad"] ;
      };
      if (isSet($_REQUEST["x_orden"])) {
      	$orden =  $_REQUEST["x_orden"] ;
      };
      if (isSet($_REQUEST["x_encargado"])) {
      	$encargado =  strtoupper( $_REQUEST["x_encargado"]) ;
      };
      if (isSet($_REQUEST["x_telresto"])) {
      	$telresto =  $_REQUEST["x_telresto"] ;
      };
      if (isSet($_REQUEST["x_responsable"])) {
      	$responsable =  strtoupper( $_REQUEST["x_responsable"]) ;
      };
      if (isSet($_REQUEST["x_telresp"])) {
      	$telresp =  $_REQUEST["x_telresp"] ;
      };
      if (isSet($_REQUEST["x_idabono"])) {
      	$idabono =  $_REQUEST["x_idabono"] ;
      };
      if (isSet($_REQUEST["x_idsoporte"])) {
      	$idsoporte =  $_REQUEST["x_idsoporte"] ;
      };
      if (isSet($_REQUEST["x_observacion"])) {
      	$observacion =  strtoupper( $_REQUEST["x_observacion"]) ;
      };
      if (isSet($_REQUEST["x_configuracion"])) {
      	$configuracion =  strtoupper( $_REQUEST["x_configuracion"]) ;
      };
      if (isSet($_REQUEST["x_comentario"])) {
      	$comentario =  strtoupper( $_REQUEST["x_comentario"]) ;
      };

      if (isSet($_REQUEST["x_email"])) {
      	$email =  $_REQUEST["x_email"] ;
      };
      if (isSet($_REQUEST["x_paginaweb"])) {
      	$paginaweb =  $_REQUEST["x_paginaweb"] ;
      };

      if (isSet($_REQUEST["x_conexion"])) {
      	$conexion =  $_REQUEST["x_conexion"] ;
      };
      
      if (isSet($_REQUEST["claveuso"])) {
      	$claveuso = $_REQUEST["claveuso"] ;
      };


      /*
      echo "idresto: ".$idresto." - Nombre: ".$nombrerest." - NomClave: ".$nombreclave;
      echo "<br>";
      echo "Usuario: ".$usuario." - Clave: ".$clave." - Dir: ".$direccion." - Loc: ".$localidad." - Prov:".$provincia;
      echo "<br>";
      echo "idregion: ".$idregion." - Prioridad: ".$prioridad." - Orden: ".$orden." Enc: ".$encargado." Tel".$telresto;
      echo "<br>";
      echo "Resp: ".$responsable." - Tel: ".$telresp." - Abono:".$idabono." - Soporte: ".$idsoporte;
      echo "<br>";
      echo "Observ: ".$observacion." - Config: ".$configuracion." - Email:".$email." - Web: ".$paginaweb;
      echo "<br>";
      */

      $SQL = "insert into r_resto (IdResto,NombreRest,User,Clave,Direccion,Localidad,Provincia,Pais,TelefonoRest,Encargado,Responsable, ";
      $SQL = $SQL . " RazonSocial,TipoIva,Cuit,Abono,TelefonoResp,Email,Ref_nombre,Ref_contacto,Ref_Telefono,PaginaWeb,Configuracion, ";
      $SQL = $SQL . " IdSoporte,Activo,IdRegion,Comentario,Prioridad,Orden,Importe,Observacion,NombreClave,Conexion,Claveuso) ";
      $SQL = $SQL . " Values ( $idresto,'$nombrerest','$usuario','$clave','$direccion','$localidad','$provincia','ARGENTINA',";
      $SQL = $SQL . " '$telresto','$encargado','$responsable','','','',$idabono,'$telresp','$email','','','','$paginaweb','$configuracion',";
      $SQL = $SQL . " $idsoporte,1,$idregion,'$comentario',$prioridad,$orden,0,'$observacion','$nombreclave','$conexion','$claveuso')";

      /*
      echo $SQL;
      echo "<br>";
      */

      $retid = mysql_query($SQL, $cid);
	  if (!$retid) {
        echo "<script type=\"text/javascript\">";
        echo "alert(\"ERROR el cliente no fue agregado !!\");";
        echo "</script>";
      } else {
        echo "<script type=\"text/javascript\">";
        echo "alert(\"El Cliente fue agregado !!\");";
        echo "</script>";
      };

      $opc="verclientes";
   };


   if ($opc=="nuevocontacto" ) {

      if (isSet($_REQUEST["idresto"])) {
      	$idresto =  $_REQUEST["idresto"] ;
      };
      $SQL = "Select Max(idPersona) as ultimo from r_telefonos Where idRest = ".$idresto;

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo("Error en la consulta");
      } else {
       if ($row = mysql_fetch_array($retid)) {
          $ultpersona=$row["ultimo"]+1;
          echo "ultimo: "+$ultpersona;
          echo "<br>";
          }
       };
       $opc="nuevocontacto";
   };

   if ($opc=="grabarcont" ) {

      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };
      if (isSet($_REQUEST["x_idpersona"])) {
      	$idpersona = $_REQUEST["x_idpersona"] ;
      };
      if (isSet($_REQUEST["x_nombre"])) {
      	$nombre = strtoupper( $_REQUEST["x_nombre"]) ;
      };
      if (isSet($_REQUEST["x_cargo"])) {
      	$cargo = strtoupper( $_REQUEST["x_cargo"]) ;
      };
      if (isSet($_REQUEST["x_telefono"])) {
      	$telefono =  $_REQUEST["x_telefono"] ;
      };
      if (isSet($_REQUEST["x_email"])) {
      	$email = strtoupper( $_REQUEST["x_email"]) ;
      };

      $SQL = "insert into r_telefonos (idRest,idPersona,Nombre,Cargo,Telefono,email) ";
      $SQL = $SQL . " Values ( $idresto,$idpersona,'$nombre','$cargo','$telefono','$email')";

      //echo $SQL;
      //echo "<br>";


      $retid = mysql_query($SQL, $cid);
	  if (!$retid) {
        echo("Error en la consulta");
      } else {
        echo("Contacto agregado con exito");
      };

      $opc="verresto";


   };

   if ( $opc == "verresto"  ) {
      if (isSet($_REQUEST["idresto"])) {
      	$idresto = $_REQUEST["idresto"] ;
      };
      $opc="verresto";

   };
   
    if ( $opc == "buscar_abonos"  ) {

      if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = strtoupper( $_REQUEST["x_buscar"]) ;
      };

      if (isSet($_REQUEST["c_regsel"])) {
      	$regsel = strtoupper( $_REQUEST["c_regsel"]) ;
      };
      
      $impago=0;
      if (isSet($_REQUEST["x_impago"])) {
      	$impago = $_REQUEST["x_impago"] ;
      };
      
      $mesact=0;
      if (isSet($_REQUEST["x_mesact"])) {
      	$mesact = $_REQUEST["x_mesact"] ;
      };
      $opc="verabonos";

   };

if ( $opc == "grabarclaves"  ) {

      if (isSet($_POST["x_mesclave"])) {
        $mesclave = $_POST["x_mesclave"] ;
      };

      if (isSet($_POST["x_anoclave"])) {
      	$anoclave = $_POST["x_anoclave"] ;
      };
      
      $ok=0;
      

      $SQL = "Select Idresto,NombreRest,Importe,Abono From r_resto";
      $SQL = $SQL . " Where Activo = 1 ";
      
      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo("Error en la consulta");
         $ok=1;
      } else {
        While ($row = mysql_fetch_array($retid)) {
            $nombrerest=$row["NombreRest"];
            $idresto=$row["Idresto"];
            $importe=$row["Importe"];
            $abono=$row["Abono"];
            
            //echo "Pedir Clave....".$nombrerest.' , '.$mesclave.' - '.$anoclave;
            //echo "<br>";
            
            $clavegen = GenClave('VENTAS',$nombrerest,$mesclave,$anoclave);
            
            $clavenom = ucwords(nombremes($mesclave))." ".$anoclave;

            $SQL1 = "UPDATE r_resto SET ClaveUso ='".$clavegen."'";
            $SQL1 = $SQL1 . " ,ClaveMes ='".$clavenom."'";
            $SQL1 = $SQL1 . " Where Idresto = ".$idresto;
            $retid1 = mysql_query($SQL1, $cid);
            if (!$retid1) {
              echo("Error en la consulta - Resto: ".$idr);
            };
            
            //echo $nombrerest.' '.$clavegen;
            //echo "<br>";
         }
       }
       /*
        $file = fopen("claves.txt", "r") or exit("Unable to open file!");
        
        while(!feof($file))
        {
            $st=trim(fgets($file));
            
            $i=strpos($st,';');
            $idr=trim(substr($st,0,$i));
            $clavegen=trim(substr($st,$i+1));
            
            if ( strlen($clavegen) == 2 ) {
               $clavegen="000".trim($clavegen);
            }
            
            if ( strlen($clavegen) == 3 ) {
               $clavegen="00".trim($clavegen);
            }
            
            if ( strlen($clavegen) == 4 ) {
               $clavegen="0".trim($clavegen);
            }
        
            //$clavegen = GenClave('VENTAS',$nombrerest,$mesclave,$anoclave);
            
            $clavenom = ucwords(nombremes($mesclave))." ".$anoclave;

            $SQL1 = "UPDATE r_resto SET ClaveUso ='".$clavegen."'";
            $SQL1 = $SQL1 . " ,ClaveMes ='".$clavenom."'";
            $SQL1 = $SQL1 . " Where Idresto = ".$idr;
            
            //echo $idr; echo "<br>";
            //echo $SQL1; echo "<br>";
      
            $retid1 = mysql_query($SQL1, $cid);
         if (!$retid1) {
              echo("Error en la consulta - Resto: ".$idr);
            };
         };
         fclose($file);
         */
            /*
            if ( $abono <> 6 ) {
               $SQL2 = "insert into r_cuotas (IdResto,IdModulo,Tipo,Anio,Mes,Valor,Pago) ";
               $SQL2 = $SQL2 . " Values ( $idresto,1,1,$anoclave,$mesclave,".$importe.",0)";
            
               $retid2 = mysql_query($SQL2, $cid);
	           if (!$retid2) {
                  $SQL3 = "Update r_cuotas Set Valor = ".$importe;
                  $SQL3 = $SQL3 . " Where Idresto = ".$idresto;
                  $retid3 = mysql_query($SQL3, $cid);
                  if (!$retid3) {
                     echo("Error en la consulta");
                  };
               };
            };
            */
            
            
         //};

       //};
      $buscar="";
      $abonosel=-1;
      $zonasel=-1;
      $orden = "idResto";
      $opc="buscar_clientes";
      $seccion="clientes";
      echo "<script type=\"text/javascript\">";
      echo "alert(\"Abonos Generados !!\");";
      echo "</script>";

   };
   
if ( $opc == "pagarabono"  ) {

      if (isSet($_REQUEST["mes"])) {
          $mes = $_REQUEST["mes"] ;
      };

      if (isSet($_REQUEST["anio"])) {
      	$anio = $_REQUEST["anio"] ;
      };
      
      if (isSet($_REQUEST["idresto"])) {
      	$idresto = $_REQUEST["idresto"] ;
      };
      
      if (isSet($_REQUEST["valor"])) {
      	$valor = $_REQUEST["valor"] ;
      };
      

      $SQL = "UPDATE r_cuotas SET Pago =".$valor;
      $SQL = $SQL . " Where IdResto = ".$idresto;
      $SQL = $SQL . " and Mes = ".$mes;
      $SQL = $SQL . " and Anio = ".$anio;
      
      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
        echo "<script type=\"text/javascript\">";
        echo "alert(\"ERROR al realizar el pago !!\");";
        echo "</script>";
      } else {
        echo "<script type=\"text/javascript\">";
        echo "alert(\"El Pago fue realizado con Exito !!\");";
        echo "</script>";
      };
      
      $opc='verabonos';

};
    
if ( $opc == "enviaremailcli"  ) {
      if (isSet($_REQUEST["x_user"])) {
          $user = $_REQUEST["x_user"] ;
      };

      if (isSet($_REQUEST["x_clave"])) {
      	$clave = $_REQUEST["x_clave"] ;
      };

      if (isSet($_REQUEST["x_email"])) {
      	$email = $_REQUEST["x_email"] ;
      };
      
      echo "<script type=\"text/javascript\">";
      echo "alert(\"Email enviado !!\");";
      echo "</script>";
      
      
      if ( $email <> '' ) {
        $html='<table>';
        $html=$html.'<tr>';

        $html=$html.'<td><span class="Estilo1">========================================</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">INSTRUCCIONES PARA OBTENER LA CLAVE</span></td>';
        $html=$html.'</tr>';
         $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">1) Ingrese a www.restosoft.com.ar</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">2) Vaya a la seccion CLIENTES</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">3) Ingrese Usuario= '.$user.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">   Ingrese Clave= '.$clave.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">4) Haga Click en VALIDAR </span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">y siga las instrucciones </span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">o simplemente obtenga su clave</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td>';
         $html=$html.'<td><span class="Estilo1">========================================</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        
        $html=$html.'</tr></table>';
        
        require_once('../htmlMimeMail5.php');

        $mail = new htmlMimeMail5();
        $mail->setFrom('RestoSoft <soporte@restosoft.com.ar>');
        $mail->setSubject('Como obtener la clave para Restsoft');
        $mail->setHTML($html);
        $mail->send(array($email));
      }
      
      $opc="verclientes";

};


?>

