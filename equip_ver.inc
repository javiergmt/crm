
<table summary="Precios">
<?
 //echo "<caption>RESTOSOFT</caption>";
$cotiz = 0;
$data_in = "http://ws.geeklab.com.ar/dolar/get-dolar-json.php";
$data_json = @file_get_contents($data_in);
if(strlen($data_json)>0)
{
  $data_out = json_decode($data_json,true);

  if(is_array($data_out))
  {
    if(isset($data_out['libre'])) {
    print "Dolar Libre: ".$data_out['libre']."<br>\n";
    }
    if(isset($data_out['blue'])) {
    print "Dolar Blue: ".$data_out['blue']."<br>\n";
    }
    $cotiz =max( $data_out['blue'],$data_out['libre']);
  }
}
?>

<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">RESTOSOFT</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">- $ -</th><th scope="col">- U$S -</th>
</tr>
</thead>
<tfoot>
<tr><th scope="row"></th><td colspan="5"></td></tr>
</tfoot>

<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'RS'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
        $precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";

        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>


<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS FEDE</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'FE'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>


<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS CITSSA</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'CI'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>

<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS CASIOTER</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'CA'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>

<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS KRETZ</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'KR'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>

<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS RES</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'RE'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>

<thead>
<tr class="odd"><th scope="row"></th><td colspan="4">EQUIPOS VARIOS</td></tr>
<tr>
<th scope="col">ID</th><th scope="col">EQUIPO</th><th scope="col">PRECIO</th><th scope="col"></th>
</tr>
</thead>


<tbody>
<?
//echo "<form name=\"formequipos\" method=\"post\" action=\"index.php?opcion=modif_equipo\" >";

  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,p.precious from e_propios p ";
  /*
  $SQL = " Select p.id,p.identif,p.descrip,p.precio,p.idtipo,p.destino,e.descrip as estado from e_propios p ";
  $SQL = $SQL . " left outer join e_estados e on e.idestado = p.idestado ";
  $SQL = $SQL . " where upper(p.descrip) like '%".$buscar."%'";
  $SQL = $SQL . " and ((".$estadosel." = -1) OR (".$estadosel." = p.idestado) )";
  $SQL = $SQL . " and ((".$tiposel." = -1) OR (".$tiposel." = p.idtipo) )";
  */
  $SQL = $SQL . " Where SUBSTRING(p.identif,1,2) = 'VS'";
  $SQL = $SQL . " order by p.identif ";

  //echo $SQL;
  //echo "<br>";

  $retid = mysql_query($SQL, $cid);

  if (!$retid) {
		echo("Error en la consulta");
  } else {
    $paso=1;

    While ($row = mysql_fetch_array($retid)) {
        $id = $row["id"];
        $identif = $row["identif"];
		$equipo = $row["descrip"];
		//$estado = $row["estado"];
		$destino = $row["destino"];
		$precio = $row["precio"];
		$precious = $row["precious"];
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

        echo "<th scope=\"row\" id=\"r100\"><a href=\"index.php?opcion=modif_equipo&idequipo=$id\">".$identif."</a></th>";
        //echo "<th scope=\"row\" id=\"r100\"><a href=\"#\">".$identif."</a></th>";

        echo "<td>".$equipo."</td>";
        if ( $precious <> 0 ) {
        echo "<td style=\"text-align:right\">".number_format($precious * $cotiz,2)."</td>";
        echo "<td style=\"text-align:right\">".number_format($precious,2)."</td>";
        } else {
        echo "<td style=\"text-align:right\">".number_format($precio,2)."</td>";
        echo "<td style=\"text-align:right\">-</td>";
        }
        echo "</tr>";

     };
   };
   //echo "<ul><li>";
   //echo "<a href=\"index.php?opcion=modif_equipo&idequipo=0\"><img src=\"images/boton_nuevo.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
   //echo "</li></ul>";

   //echo "</form>";
   ?>

</tbody>



</table>

