<?
  echo "<table summary=\"Clientes\">";
  echo "<form name=\"formcliedit\" method=\"post\" action=\"index.php\" >";

  if ( $idresto <> 0 ) {
  $SQL = " Select * from r_resto r";
  $SQL = $SQL . " where ( IdResto = ".$idresto." )";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {

    if ($row = mysql_fetch_array($retid)) {
        $nombrerest = $row["NombreRest"];
        $user = $row["User"];
        $clave = $row["Clave"];
        $direccion = $row["Direccion"];
		$localidad = $row["Localidad"];
        $provincia = $row["Provincia"];
        $telefonorest = $row["TelefonoRest"];
        $encargado = $row["Encargado"];
        $responsable = $row["Responsable"];
        $telefonoresp = $row["TelefonoResp"];
		$idabono = $row["Abono"];
		$email = $row["Email"];
        $configuracion = $row["Configuracion"];
        $idsoporte = $row["IdSoporte"];
        $activo = $row["Activo"];
        $idregion = $row["IdRegion"];
        $claveuso = $row["Claveuso"];
        $clavemes = $row["ClaveMes"];
        $nombreclave = $row["NombreClave"];
        $importe = $row["Importe"];
        $observacion = $row["Observacion"];
        $conexion = $row["Conexion"];
        $comentario = $row["Comentario"];
        $prioridad = $row["Prioridad"];
        $orden = $row["Orden"];
        $mapa = $row["mapa"];
        $version = $row["Version"];
        $factelec = $row["FactElec"];
      };
   };
   } else {

        $nombrerest = '';
        $user = '';
        $clave = '1234';
        $direccion = '';
		$localidad = '';
        $provincia = '';
        $telefonorest = '';
        $encargado = '';
        $responsable = '';
        $telefonoresp = '';
		$idabono = 1;
		$email = '';
        $configuracion = '';
        $idsoporte = 1;
        $activo = 1;
        $idregion = 1;
        $claveuso = '';
        $clavemes = '';
        $nombreclave = '';
        $importe = 0;
        $observacion = '';
        $conexion = '';
        $comentario = '';
        $prioridad = 9999;
        $orden = 9999;
        $mapa = '';
        $version = '';
        $facelec = 0;
        };
        echo "<ul><li>Nombre</li></ul>";
        echo "<input name=\"x_nombrerest\" type=\"text\" size=\"50\" class=\"ingresotx\" value='".$nombrerest."'></input>";
        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Direccion, Localidad, Provincia</li></ul>";
        echo "<input name=\"x_direccion\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$direccion."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_localidad\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$localidad."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_provincia\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$provincia."'></input>";
        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Region&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_region\" >";

         $SQL1 = " select * ";
         $SQL1 = $SQL1 . " from r_regiones ";
	     $SQL1 = $SQL1 . " Order by IdRegion";
         $retid1 = mysql_query($SQL1, $cid);
	     if (!$retid1) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid1)) {
				$sidregion = $row["IdRegion"];
      		    $sregion = $row["Descripcion"];
      		    if ( $idregion == $sidregion ) {
                  echo "<option selected value=".$sidregion." >".$sregion."</option>";
                } else {
                  echo "<option value=".$sidregion." >".$sregion."</option>";
                }
            }
         }
        echo "</select>";
        echo "</li></ul>";
        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Encargado, Telefono Resto, Mail de contacto</li></ul>";
        echo "<input name=\"x_encargado\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$encargado."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_telefonorest\" type=\"text\" size=\"10\" class=\"ingresotx\" value='".$telefonorest."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_email\" type=\"text\" size=\"30\" class=\"ingresotx\" value='".$email."'></input>";

        echo "<ul><li>Responsable, Telefono Responsable</li></ul>";
        echo "<input name=\"x_responsable\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$responsable."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_telefonoresp\" type=\"text\" size=\"10\" class=\"ingresotx\" value='".$telefonoresp."'></input>";

        echo "<ul><li>&nbsp;</li></ul>";

        echo "<ul><li>Tipo Abono&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_abono\" >";

         $SQL1 = " select * ";
         $SQL1 = $SQL1 . " from r_abonos ";
	     $SQL1 = $SQL1 . " Order by idAbono";
         $retid1 = mysql_query($SQL1, $cid);
	     if (!$retid1) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid1)) {
				$sidabono = $row["idAbono"];
      		    $sabono = $row["Descripcion"];
      		    if ( $idabono == $sidabono ) {
                  echo "<option selected value=".$sidabono." >".$sabono."</option>";
                } else {
                  echo "<option value=".$sidabono." >".$sabono."</option>";
                }
            }
         }
        echo "</select>";
        echo "</li></ul>";
        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Nombre Clave, Importe</li></ul>";
        echo "<input name=\"x_nombreclave\" type=\"text\" size=\"30\" class=\"ingresotx\" value='".$nombreclave."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_importe\" type=\"text\" size=\"20\" class=\"ingresotx\" value=".$importe."></input>&nbsp;&nbsp;";
        echo "<ul><li>Mes, Clave</li></ul>";
        echo "<input name=\"x_clavemes\" type=\"text\" size=\"30\" class=\"ingresotx\" value='".$clavemes."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_claveuso\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$claveuso."'></input>";
        echo "<ul><li>Version de Mod. Ventas</li></ul>";
        echo "<input name=\"x_version\" type=\"text\" size=\"20\" class=\"ingresotx\" value='".$version."'></input>";
        
        echo "   - Facturacion Electronica:&nbsp;";
        if ( $factelec == 1 ) {
            echo "<input type=\"checkbox\" name=\"x_factelec\" checked></input>";
        } else {
            echo "<input type=\"checkbox\" name=\"x_factelec\" ></input>";
        }
        echo "</li></ul>";


        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Acceso Web, Usuario, Clave</li></ul>";
        echo "<input name=\"x_user\" type=\"text\" size=\"15\" class=\"ingresotx\" value='".$user."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_clave\" type=\"text\" size=\"15\" class=\"ingresotx\" value='".$clave."'></input>";
        echo "<ul><li>&nbsp;</li></ul>";


        echo "<ul><li>Configuracion </li></ul>";
        echo "<textarea name=\"x_configuracion\" rows=\"4\" wrap=\"PHYSICAL\" cols=\"60\">$configuracion</textarea>";
        echo "<ul><li>Conexiones</li></ul>";
        echo "<textarea name=\"x_conexion\" rows=\"4\" wrap=\"PHYSICAL\" cols=\"60\" class=\"ingresotx\">$conexion</textarea>";
        echo "<ul><li>Observaciones</li></ul>";
        echo "<textarea name=\"x_observacion\" rows=\"4\" wrap=\"PHYSICAL\" cols=\"60\" class=\"ingresotx\">$observacion</textarea>";
        echo "<ul><li>&nbsp;</li></ul>";
        
        echo "<ul><li>Soporte Tecnico&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_idsoporte\" >";

         $SQL2 = " select * ";
         $SQL2 = $SQL2 . " from r_soporte ";
	     $SQL2 = $SQL2 . " Order by idSoporte";
         $retid2 = mysql_query($SQL2, $cid);
	     if (!$retid2) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid2)) {
				$sidsoporte = $row["idSoporte"];
      		    $ssoporte = $row["Empresa"];
      		    if ( $idsoporte == $sidsoporte ) {
                  echo "<option selected value=".$sidsoporte." >".$ssoporte."</option>";
                } else {
                  echo "<option value=".$sidsoporte." >".$ssoporte."</option>";
                }
            }
         }
        echo "</select>";
        echo "</li></ul>";
        echo "<ul><li>&nbsp;</li></ul>";

        echo "<ul><li>Comentario Pagina web </li></ul>";
        echo "<textarea name=\"x_comentario\" rows=\"4\" wrap=\"PHYSICAL\" cols=\"60\">$comentario</textarea>";
        echo "<ul><li>Prioridad, Orden</li></ul>";
        echo "<input name=\"x_prioridad\" type=\"text\" size=\"15\" class=\"ingresotx\" value='".$prioridad."'></input>&nbsp;&nbsp;";
        echo "<input name=\"x_orden\" type=\"text\" size=\"15\" class=\"ingresotx\" value='".$orden."'></input>";
        echo "<ul><li>Link Google map </li></ul>";
        echo "<textarea name=\"x_mapa\" rows=\"8\" wrap=\"PHYSICAL\" cols=\"60\">$mapa</textarea>";
        echo "<ul><li>&nbsp;</li></ul>";


        echo "<input type=\"hidden\" name=\"x_idresto\" value=$idresto>";
        echo "<input type=\"hidden\" name=\"idresto\" value=$idresto>";
        echo "<input type=\"hidden\" name=\"opcion\" >";



   echo "<ul><li>";
   echo "<a href=\"#\" onClick=\"javascript:pedirgrabarcliente()\"><img src=\"images/boton_grabar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   echo "<a href=\"#\" onClick=\"javascript:pedirampliarcliente()\"><img src=\"images/mas_info.jpg\" width=\"60\" height=\"14\" border=\"0\"></a>";
   echo "</li></ul>";
   
   echo "<ul><li>&nbsp;</li></ul>";
   echo "<ul><li>&nbsp;</li></ul>";

   echo "</form>";
   echo "</table>";
 ?>
