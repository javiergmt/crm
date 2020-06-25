<?
  echo "<table summary=\"Equipos\">";
  echo "<form name=\"formequipoedit\" method=\"post\" action=\"index.php?opcion=grabar_equipo\" >";

  $SQL = " Select p.*,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where id = ".$idequipo;

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;
    if ($row = mysql_fetch_array($retid)) {
        $idequipo = $row["id"];
        $identif = $row["identif"];
		$equipo = trim($row["descrip"]);
		$idestado = $row["idestado"];
        $idtipo = $row["idtipo"];
        $fecha = $row["fecha"];
        $destino = $row["destino"];
        $precio = $row["precio"];
        $precious = $row["precious"];
        $origen = $row["origen"];
     } else {
        $now=time();
        $fecha = strftime("%d/%m/%Y",$now);
        $idequipo = 0;
        $identif = "";
		$equipo = "";
		$idestado = 1;
        $idtipo = 1;
        $destino = "";
        $precio = 0;
        $precious = 0;
        $origen = "";
     };
        echo "<ul><li>Identificador</li></ul>";
        echo "<input name=\"x_identif\" type=\"text\" size=\"50\" class=\"ingresotx\" value=".$identif."></input>";
        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Detalle</li></ul>";
        echo "<input name=\"x_descrip\" type=\"text\" size=\"50\" class=\"ingresotx\" value=\"".$equipo."\"></input>";

        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Tipo&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_idtipo\" >";

         $SQL1 = " select idtipo,descrip ";
         $SQL1 = $SQL1 . " from e_tipos ";
	     $SQL1 = $SQL1 . " Order by idtipo";
         $retid1 = mysql_query($SQL1, $cid);
	     if (!$retid1) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid1)) {
				$sidtipo = $row["idtipo"];
      		    $stipo = $row["descrip"];
      		    if ( $idtipo == $sidtipo ) {
                  echo "<option selected value=".$sidtipo." >".$stipo."</option>";
                } else {
                  echo "<option value=".$sidtipo." >".$stipo."</option>";
                }
            }
         }
        echo "</select>";
        echo "</li></ul>";
        
        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Estado&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
        echo "<select name=\"x_idestado\" >";

         $SQL1 = " select idestado,descrip ";
         $SQL1 = $SQL1 . " from e_estados ";
	     $SQL1 = $SQL1 . " Order by idestado";
         $retid1 = mysql_query($SQL1, $cid);
	     if (!$retid1) { echo("Error en la consulta"); }
	     else {
			while ($row = mysql_fetch_array($retid1)) {
				$sidestado = $row["idestado"];
      		    $sestado = $row["descrip"];
      		    if ( $idestado == $sidestado ) {
                  echo "<option selected value=".$sidestado." >".$sestado."</option>";
                } else {
                  echo "<option value=".$sidestado." >".$sestado."</option>";
                }
            }
         }
        echo "</select>";
        echo "</li></ul>";
        
        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Fecha</li></ul>";
        echo "<input name=\"x_fecha\" type=\"text\" size=\"50\" class=\"ingresotx\" value=".$fecha."></input>";

        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Destino</li></ul>";
        echo "<input name=\"x_destino\" type=\"text\" size=\"50\" class=\"ingresotx\" value='".$destino."'></input>";

        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Precio en Pesos</li></ul>";
        echo "<input name=\"x_precio\" type=\"text\" size=\"50\" class=\"ingresotx\" value=".$precio."></input>";

        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Precio en dolares</li></ul>";
        echo "<input name=\"x_precious\" type=\"text\" size=\"50\" class=\"ingresotx\" value=".$precious."></input>";


        echo "<ul><li>&nbsp;</li></ul>";
        echo "<ul><li>Origen</li></ul>";
        echo "<input name=\"x_origen\" type=\"text\" size=\"50\" class=\"ingresotx\" value='".$origen."'></input>";

        echo "<ul><li>&nbsp;</li></ul>";
        echo "<input type=\"hidden\" name=\"x_idequipo\" value=$idequipo>";
        echo "<input type=\"hidden\" name=\"opcion\">";
     };


   echo "<ul><li>";
   echo "<a href=\"#\" onClick=\"javascript:pedirgrabarequipo()\"><img src=\"images/boton_grabar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   if ( $idequipo <> 0 ) {
   echo "<a href=\"#\" onClick=\"javascript:pedirborrarequipo()\"><img src=\"images/boton_borrar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   }
   echo "</li></ul>";


   echo "</form>";
   echo "</table>";
 ?>
