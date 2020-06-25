<?php
   include_once("session/inisess.inc");
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>Open RestoSoft CRM</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link href="style.css" rel="stylesheet" type="text/css">
<?php
  include_once("funcjs.inc");

?>
</head>

<?php

   $opc='buscar_clientes';
   $seccion='clientes';

   if (isSet($_REQUEST["opcion"])) {
      $opc = $_REQUEST["opcion"] ;
   } else {
         if (isSet($_POST["opcion"])) {
      $opc = $_POST["opcion"] ;
     }
   };
   
   //echo $opc;
   //echo "<br>";
   
   $buscar = "";
   $regsel = -1;
   $clisel = -1;
   $idampliar=0;
   $tiposel = -1;
   $estadosel = - 1;
   $impago = 0;
   $mesact = 0;
   $activo = 1;
   $absel = -1;
   $estado = 'P';
   $orden = 'idResto';
   if ( !IsSet($_SESSION['tipoorden'] ) ) {
      $_SESSION['tipoorden'] = '';
   };
   
   include_once("data/dbparams.inc");
   include_once("data/lib_data.inc");
   $cid = conectar($host,$usr,$pwd);
   selDB($db, $cid);
   
   /*
   If (!IsSet($_SESSION['id'])) {
      include("carga_clientes.inc");
   };
   */
   include_once("cons_funciones.inc");
   include_once("equip_funciones.inc");
   include_once("clientes_funciones.inc");



   if ( $opc == "usuarios"  ) {
      if (isSet($_REQUEST["modoOp"])) {
      	$modoOp = $_REQUEST["modoOp"] ;
      };
      if ( $modoOp == "login" ) {
         $x_usuario = "VOID";
         if (isSet($_POST["x_usuario"])) {
      	    $x_usuario = $_POST["x_usuario"] ;
      	    $estadosel=1;
         };

         if (isSet($_POST["x_password"])) {
      	    $x_password = $_POST["x_password"] ;
         };
         //echo "validamos"; echo "<br>";
         $_SESSION['usuario'] = $x_usuario;
         if ( ValidarUsuario($cid,$x_usuario,$x_password) == 0 ){
            $opc='inicio';
            $_SESSION['region'] = -1;
            $_SESSION['abono'] = -1;
            //echo "validacion ok"; echo "<br>";
         } else {
            $opc='login';
            $x_usuario = "VOID";
            $_SESSION['usuario'] = "VOID";
            //echo "validacion incorrecta"; echo "<br>";

         };
      } else {
        $opc='inicio';
        //echo "volvemos al inicio"; echo "<br>";
      };
   };


   if ( $opc == "buscar"  ) {

      if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = strtoupper( $_REQUEST["x_buscar"]) ;
      };
      
      if (isSet($_REQUEST["c_regsel"])) {
      	$regsel = strtoupper( $_REQUEST["c_regsel"]) ;
      	$_SESSION['region'] = $regsel;
      };
      
      if (isSet($_REQUEST["c_absel"])) {
      	$absel = strtoupper( $_REQUEST["c_absel"]) ;
      	$_SESSION['abono'] = $absel;
      };
      $opc="buscar_cli";

   };

   if ($opc=="desconectar" ) {
      $_SESSION["usuario"]="VOID";
      $_SESSION["idoper"]=0;
   };

    /*
    Activar esto para hace el login de usuario
    
    if (isSet($_SESSION["usuario"])) {
       if ($_SESSION["usuario"]=="VOID"){
           $opc="login";

       };
   } else {
     $opc="login";

   };
   */
   
   //echo $_SESSION['usuario']." ".$mens;
   //echo $opc." ".$seccion;
   //echo "<br>";


?>
<body>
<div id="mainPan">
  <div id="leftPan">
    <ul class="one">
      <?php //if ( $opc == 'inicio' ) {  ?>
      <li><h2>Menu</h2></li>
      <li><a href="index.php?opcion=buscar_consulta&x_estado=P">Consultas</a></li>
      <li><a href="index.php?opcion=buscar_clientes">Clientes</a></li>
      <li><a href="index.php?opcion=buscar_equipos">Equipos</a></li>
      <li><a href="index.php?opcion=gen_abonos">Abonos</a></li>
      <? //} ?>
    </ul>

    <div id="fastformPan">
       <?php
        switch ( trim($seccion) ) {

        case "consultas": {
             include("cons_seccion.inc");

         } break;
         
        case "clientes": {
             include("clientes_seccion.inc");

         } break;
         
        case "equipos": {
             include("equip_seccion.inc");
         } break;

         };
         ?>

    </div>

  </div>
  <div id="rightPan">
    <div id="topPan"> <a href="http://www.restosoft.com.ar/"><img src="images/cabezal_crm.gif" title="RestoSoft" alt="RestoSoft" width="550" height="50" border="0"  class="logo"/></a>
      <!--
      <ul>
        <li class="pen"><a href="http://www.free-css.com/">pen</a></li>
        <li class="book"><a href="http://www.free-css.com/">book</a></li>
        <li class="calculator"><a href="http://www.free-css.com/">calculator</a></li>
      </ul>
      -->

    </div>
    <div id="bodyPan">

       <?

         switch ( trim($opc) ) {
         case "verconsultas": {
              echo "<h2>Consultas</h2>";
              include("cons_ver.inc");
              };
              break;
         case "ver_consulta": {
              echo "<h2>Consulta Nro ".$idampliar."</h2>";
              include("cons_editar.inc");
              };
              break;
         case "editar_consulta": {
              echo "<h2>Editar Consulta Nro ".$idampliar."</h2>";
              include("cons_editar.inc");
              };
              break;
         case "nueva_consulta": {
              echo "<h2>Nueva Consulta </h2>";
              include("cons_nueva.inc");
              };
              break;
         case "buscar_equipos": {
              echo "<h2>Equipos</h2>";
              include("equip_ver.inc");
              };
              break;
         case "modif_equipo": {
              if ( $idequipo == 0 ) {
                echo "<h2>Nuevo Equipo</h2>";
              } else {
                echo "<h2>Editar Equipo id ".$idequipo."</h2>";
              };
              include("equip_editar.inc");
              };
              break;
         case "buscar_clientes": {
              echo "<h2>Clientes</h2>";
              include("clientes_ver.inc");
              };
              break;
         case "ampliar_cli": {
              echo "<h2>Clientes</h2>";
              include("clientes_consulta.inc");
              };
              break;
         case "editar_cli": {
              echo "<h2>Clientes</h2>";
              include("clientes_editar.inc");
              };
              break;
         case "gen_abonos": {
              echo "<h2>Abonos</h2>";
              include("abonos.inc");
              };
              break;
         };
      ?>


  </div>
</div>

</body>
</html>


<?php
function ValidarUsuario($cid,$usuario,$pass) {

	$ret = 0;
	$usuario=strtoupper($usuario);
	$SQL = " Select * from r_operador ";
    $SQL = $SQL . " Where ( Upper(Nombre) = '".$usuario."' )";

    //echo $SQL;
    //echo "<br>";

    $retid = mysql_query($SQL, $cid);

    if (!$retid) {
        echo("Error en la consulta");
    } else {
    	if ($row = mysql_fetch_array($retid)) {
        	$clave = $row["Clave"];
        	$_SESSION["idoper"] = $row["IdOperador"];
        	If ($clave <> $pass ) {
               $ret=1;
            } else {

            };
        } else {
          $ret=1;

        }
    };
    return $ret;
};


function traer_comentario($cid,$id) {

	$ret = "";
	$SQL = " Select Comentario from r_resto ";
    $SQL = $SQL . " Where ( Idresto = ".$id." )";

    //echo $SQL;
    //echo "<br>";

    $retid = mysql_query($SQL, $cid);

    if (!$retid) {
        echo("Error en la consulta");
    } else {
    	if ($row = mysql_fetch_array($retid)) {
        		$ret = $row["Comentario"];
        };
    };
    return $ret;
};


Function crear_semilla() {
   list($usec, $sec) = explode(" ", microtime());
   return (float) $sec + ((float) $usec * 100000);
};

Function GenClave($modulo,$nombre,$mes,$anio){
  $ARREGLO1 = '2698745031';
  $ARREGLO2 = '9403517268';
  $cEmpre =StrToUpper(Trim($nombre));
  $cNomb ='';
  $resultado='';

  //echo "Generando Clave....".$modulo.' , '.$nombre.' , '.$mes.' - '.$anio;
  //echo "<br>";

  for ($ni = 0; $ni < strlen($cEmpre); $ni++) {
    $cS = substr($cEmpre,$ni,1);
     If ( substr($cEmpre,$ni,1)<>' ' ) {
        $cNomb=$cNomb.(Ord($cS));
     };
   };

  if ( StrtoUpper($modulo) <> 'VENTAS')  {
     $cModulo=StrToUpper(Trim($modulo));
     for ($ni = 1; $ni <= strlen($cModulo); $ni++) {
         $cS = substr($cModulo,$ni-1,1);
         $cNomb=Substr($cNomb,0,($ni-1)*2+1).(Ord($cS)). Substr($cNomb,(($ni-1)*2+1)-1,StrLen($cNomb));

     };
  };

  //echo $cNomb;
  //echo "<br>";

  if (StrtoUpper($modulo) <> 'VENTAS') {
    $largo=20;
  } else {
    $largo=10;
  };

  //echo strlen($cNomb);
  //echo "<br>";

  If ( strLen($cNomb) >= $largo ) {
     $cNomb=Substr($cNomb,0,$largo);
  } else {
      for ($ni = 0; $ni <= ( $largo - strlen($cNomb ) ); $ni++) {
           $cNomb=$cNomb.'1';
      }
  }

  //echo $cNomb;
  //echo "<br>";

  if ( ($mes == 0) and ($anio == 0) ) {
      if (StrLen($cNomb) > 6) {
         $cNomb=Subtr($cNomb,1,6);
      } else {
         $nr=6 - strlen(trim($cNomb));
         If ( $nr < 0 ) {
            $nr=0;
         };
         $cNomb=str_repeat('0',$nr).trim($cNomb);
      };

      $cNomb=substr($cNomb,1,1).'6'.Substr($cNomb,2,1).'7'.substr($cNomb,3,1).'3'.Substr($cNomb,4,1).Substr($cNomb,5,1).'6'.Substr($cNomb,6,1);

      $Resultado='';
      for ($ni = 0; $ni < 10; $ni++) {
          //$indice=( ( Pos( Substr($cNomb,1,$ni),$ARREGLO1) + $ni + strlen($nombre) ) mod strlen($ARREGLO1) ) +1;
          $naux = (strpos( $ARREGLO1,Substr($cNomb,$ni,1) ) +1)+ ($ni + 1) + strlen($nombre) ;
          $naux2= strlen($ARREGLO1);
          $indice =fmod( $naux , $naux2 )+1 ;
          $Resultado=$Resultado . Substr($ARREGLO2,$indice-1,1);
          };

   } else {
      $Resultado='';
      if (StrToUpper($modulo) <> 'VENTAS') {
          for ($ni = 0; $ni < 10; $ni++) {
            //$indice=((Pos(Substr($cNomb,1,$ni),$ARREGLO1) + $ni + strlen($nombre)) mod strlen($ARREGLO1)) +1;

             $naux = (strpos( $ARREGLO1,Substr($cNomb,$ni,1) ) +1)+ ($ni + 1) + strlen($nombre) ;
             $naux2= strlen($ARREGLO1);
             $indice =fmod( $naux , $naux2 )+1 ;
             $Resultado=$Resultado . Substr($ARREGLO2,$indice-1,1);

          };
          $cNomb=$Resultado;
    };

    //=====================================================================================================

    if ( fmod( $mes,2 ) == 0 ) {
       $nV= ($anio.$mes)*13;
    } else {
       $nV= ($anio.$mes)*13;
    }

    //echo $anio.' - '.$mes.' - '.$nV;
    //echo "<br>";


    $cNomb = $cNomb;
    $ndoble = ( $cNomb * $nV);

    //echo $ndoble;
    //echo "<br>";

    $nCl=fmod( $ndoble , 148933);
    $nr=5 - strlen(trim($nCl));
    If ( $nr < 0 ) {
     $nr=0;
    };
    $resultado = str_repeat('0',$nr).substr ( trim($nCl),0,5);

   };


    //echo $cNomb.' - '.$nV.' - '.$nCl.' - '.$mes.' - '.$anio.' - '.$resultado;
    //echo "<br>";

    return($resultado);
};

Function GenClaveAnt($nombre,$mes,$anio){
  $ARREGLO1 = '2698745031';
  $ARREGLO2 = '9403517268';
  $cEmpre =StrToUpper(Trim($nombre));
  $cNomb ='';
  $resultado='';

  for ($ni = 0; $ni < strlen($cEmpre); $ni++) {
    $cS = substr($cEmpre,$ni,1);
     If ( substr($cEmpre,$ni,1)<>' ' ) {
        $cNomb=$cNomb.(Ord($cS));
     };
   };

   If ( strlen($mes) == 2 ) {
      $mes = substr($mes,1,1);
   };

   If ( strlen($cNomb)  > 10 ) {
     $cNomb = substr($cNomb,0,10);
   } else {
    for ($ni = 0; $ni <= 10 - strlen($cNomb); $ni++) {
      $cNomb = $cNomb.'1';
    };
   };
   $nresto = fmod($mes,2);
    if  ( $nresto == 0 )  {
       $nV = ($anio.$mes)*13;
    } else {
       $nV = ($anio.$mes)*13;
    };

    $nCl=fmod( $cNomb*$nV , 148933);
    $nr=5 - strlen(trim($nCl));
    If ( $nr < 0 ) {
     $nr=0;
    };
    $resultado = str_repeat('0',$nr).substr ( trim($nCl),0,5);

    //echo $mes.' - '.$anio.' - '.$resultado;
    //echo "<br>";

    return($resultado);
};

function nombremes($mes){
 //setlocale(LC_TIME, 'spanish');
 //$nombre=strftime("%B",mktime(0, 0, 0, $mes, 1, 2000));
 
  switch ( trim($mes) ) {
        case "01": {
             $nombre="ENERO"; } break;
        case "02": {
             $nombre="FEBRERO"; } break;
        case "03": {
             $nombre="MARZO"; } break;
        case "04": {
             $nombre="ABRIL"; } break;
        case "05": {
             $nombre="MAYO"; } break;
        case "06": {
             $nombre="JUNIO"; } break;
        case "07": {
             $nombre="JULIO"; } break;
        case "08": {
             $nombre="AGOSTO"; } break;
        case "09": {
             $nombre="SEPTIEMBRE"; } break;
        case "10": {
             $nombre="OCTUBRE"; } break;
        case "11": {
             $nombre="NOVIEMBRE"; } break;
        case "12": {
             $nombre="DICIEMBRE"; } break;



         };
 
 
 return $nombre;
}

/*
select * from programadores
where Upper(nombre) like "%MI%"
*/

?>
