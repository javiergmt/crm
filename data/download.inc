<?
	function validaBajada($usuario, $nivelUsuario, $archivo, $conexion) {
		$SQL = " select Pub.IdPublica as Id, Pub.IdFuenteCEB, Pub.NombrePDF, ";
		$SQL = $SQL . " F.pago as pago, F.nivelMinimo as nivelPub "; 
		$SQL = $SQL . " from NT_Publica Pub ";
		$SQL = $SQL . "       inner join NT_FuentesCEB F ";
		$SQL = $SQL . "       on Pub.IdFuenteCEB = F.IdFuente ";
		$SQL = $SQL . " where  ";
		$SQL = $SQL . "  Pub.NombrePDF = '$archivo' " ;
		
		$retid = OpenQuery($SQL, $conexion); 
		if (!$retid) { 
			echo "Error interno: Error al consultar";
		} else {
			if ($row = proximo($retid)) {
				//$resul = ( ($row["pago"]=="N") or ($nivelUsuario >= 2) );
				if ( $row["nivelPub"]<= $nivelUsuario ) {
					
					//nivelSeleccion es el nivel en el que el uuario elige 1 pub. de 3 posibles
					$nivelSeleccion=3;
					if (($row["pago"]=="N") or ($nivelUsuario<>$nivelSeleccion)) {
						//No es necesario validar publicaciones elegidas
						$resul = true;
					} else {
						//Valido que la pub. sea elegida por el usuario
						$SQL = "Select idFuenteCeb ";
						$SQL = $SQL . " From UsrWebPub ";
						$SQL = $SQL . " Where ";
						$SQL = $SQL . " idUsuario = '$usuario' ";
						$SQL = $SQL . " and idFuenteCeb = " . $row["IdFuenteCEB"];
						
						$retid = OpenQuery($SQL, $conexion); 
						if ($row = proximo($retid)) {
							//la publicacion esta dentro de las elegidas por el usuario
							$resul = true;
						} else {
							//No es publicacion elegida por el usuario
							$resul = false;
						};
					};
					
				} else {
					//El usuario no tiene derechos suficientes
					$resul = false;
				};	
			} else {
				//No se encuentra un archivo que cumple 
				$resul = false;
			};
		};
	
		return $resul;
	};

	function download($usuario, $nivelUsuario,$ruta,$archivo, $nombreBajada, $contentType, $conexion) {
		if (validaBajada($usuario,$nivelUsuario,$archivo,$conexion)) {
			if ($contentType=="") {
				//Fijo un tipo de archivo por defecto
				$contentType = "application/pdf";
			};
			header("Content-type: $contentType");
			
			//El nombre que aparecer� al bajar el archivo
			header("Content-Disposition: attachment; filename=$nombreBajada");
			
			readfile($ruta."/".$archivo);			
		} else {
			header("Location: exclusivo.php");
/*
			?>
			<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
			<HTML><HEAD><TITLE>Restringido</TITLE>
			<META content="FINANZAS, NOTICIAS" name=keywords>
			<META content="Todav�a nada." name=description>
			<META content="text/html; charset=iso-8859-1" 
			http-equiv=Content-Type><HTTP-EQUIV="PRAGMA" CONTENT="NO-CACHE">
			<link rel="stylesheet" href="abeceb.css" type="text/css">
			<META content="MSHTML 5.00.2614.3500" name=GENERATOR>
			<style>
			BODY {
			SCROLLBAR-FACE-COLOR: #FFFFFF;
			SCROLLBAR-HIGHLIGHT-COLOR: #003300;
			SCROLLBAR-SHADOW-COLOR: #FF3300;
			SCROLLBAR-3DLIGHT-COLOR: #FFFFFF;
			SCROLLBAR-ARROW-COLOR:  #FF3300;
			SCROLLBAR-TRACK-COLOR: #FFFFFF;
			SCROLLBAR-DARKSHADOW-COLOR: #FFFFFF;
			}
			</style>
			<META NAME="ROBOTS" CONTENT="INDEX, FOLLOW"></head>
			<BODY bgColor=white leftMargin=0 topMargin=0 marginheight="0" marginwidth="0">
			<? */
			/*
			
			echo "<table width=\"700\" border=\"0\" cellspacing=\"8\" cellpadding=\"0\" height=\"258\" >";
  			echo "<tr>";
    			echo "<td align=\"left\" valign=\"top\" > <span class=\"textosGenerales\">Para ver toda";
      			echo " la informaci&oacute;n disponible, debe ingresar su nombre de usuario y clave.<br>";
      			echo "Si no es un usuario registrado, podr&aacute; suscribirse a uno de <a href=\"contenido.php?modoSel=planes\" target=\"contenido\" class=\"textosGeneralesBoldRojo\">nuestros planes</a></td>";
    			echo "</tr>";
			echo "</table>";
			?>
			</BODY></HTML>
			<?
				*/
		};
	};
?>
