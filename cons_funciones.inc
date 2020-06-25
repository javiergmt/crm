
<?
  /*
  if ( $opc == "buscarconsulta"  ) {

      if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = strtoupper( $_REQUEST["x_buscar"]) ;
      };

      if (isSet($_REQUEST["c_clisel"])) {
      	$clisel = strtoupper( $_REQUEST["c_clisel"]) ;
      };
      $opc="veracciones";

   };
   */
   if ( $opc == "buscar_consulta"  ) {

      if (isSet($_REQUEST["x_buscar"])) {
      	$buscar = strtoupper( $_REQUEST["x_buscar"]) ;
      };
      
      if (isSet($_REQUEST["x_estado"])) {
      	$estado = strtoupper( $_REQUEST["x_estado"]) ;
      };

      if (isSet($_REQUEST["c_clisel"])) {
      	$clisel = strtoupper( $_REQUEST["c_clisel"]) ;
      };
      
      $opc="verconsultas";
      $seccion='consultas';

   };


   if ( $opc == "ampliar_cons"  ) {

      if (isSet($_REQUEST["idampliar"])) {
      	$idampliar = $_REQUEST["idampliar"] ;
      };
      if (isSet($_REQUEST["idresto"])) {
      	$idresto = $_REQUEST["idresto"] ;
      };
      $opc="ver_consulta";
      $seccion='consultas';
   };

   if ( $opc == "grabar_nueva_consulta"  ) {

      $now=time();
      $fecha = strftime("%d/%m/%Y",$now);
      $hora = strftime("%H:%M",$now);

   
      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      };
      if (isSet($_REQUEST["x_consulta"])) {
      	$consulta = $_REQUEST["x_consulta"] ;
      };
      if (isSet($_REQUEST["x_respuesta"])) {
      	$respuesta = $_REQUEST["x_respuesta"] ;
      };
      if (isSet($_REQUEST["x_estado"])) {
      	$estado = $_REQUEST["x_estado"] ;
      };
      if (isSet($_REQUEST["x_canal"])) {
      	$canal = $_REQUEST["x_canal"] ;
      };
      if (isSet($_REQUEST["x_oper"])) {
      	$oper = $_REQUEST["x_oper"] ;
      };
      

      //echo $fecha." ".$hora." - ".$idresto." - ".$estado." - ".$consulta." - ".$respuesta." - ".$canal." - ".$oper;
      //echo "<br>";
      
      $idconsulta=1;
      $SQL = "SELECT MAX(IdConsulta) as mcons FROM r_consultas ";
      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
           echo("Error en la consulta");
      } else {
           if ($row = mysql_fetch_array($retid)) {
            $idconsulta=$row["mcons"]+1;
           }
      };

      $SQL = "insert into r_consultas (Idresto,IdConsulta,IdOperador,Fecha,Hora,Consulta,Estado,IdCanal,Respuesta) ";
      $SQL = $SQL . "Values ( $idresto,$idconsulta,$oper,'$fecha','$hora','$consulta','$estado',$canal,'$respuesta')";

      $retid = mysql_query($SQL, $cid);
      if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR al grabar la nueva consulta\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"Nueva Consulta grabada con Nro".$idconsulta." !!\");";
         echo "</script>";
      }
      

      If ( $estado <> 'F' ) {

        $resto='';
        $SQL = "Select NombreRest from r_resto Where Idresto =".$idresto;
        $retid = mysql_query($SQL, $cid);
        if ($retid) {
           $row = mysql_fetch_array($retid);
           $sresto = $row["NombreRest"];
        };

        $scanal='';
        $SQL = "Select Descripcion from r_canales Where IdCanal =".$canal;
        $retid = mysql_query($SQL, $cid);
        if ($retid) {
           $row = mysql_fetch_array($retid);
           $scanal = $row["Descripcion"];
        };
        
        $soper='';
        $SQL = "Select Nombre from r_operador Where IdOperador =".$oper;
        $retid = mysql_query($SQL, $cid);
        if ($retid) {
           $row = mysql_fetch_array($retid);
           $soper = $row["Nombre"];
        };
        
        /*N

        require_once('../htmlMimeMail5.php');
        
        $email='javiergmt@gmail.com';
        $mail = new htmlMimeMail5();
        $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
        $mail->setSubject('Nueva consulta');
        $mail->setText('Nueva consulta');
        $mail->setCc('nmusso@gmail.com');
        $mail->setHTML('

        <table width="367" border="0" cellspacing="0" cellpadding="0">
        <tr>
        <td><span class="Estilo1">CLIENTE: ('.$idresto.' )  '.$sresto.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">CANAL: '.$scanal.' - OPER: '.$soper.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">------------ CONSULTA  --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$consulta.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">----------- RESPUESTAS --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$respuesta.'</span></td>
        </tr>
        <tr>
        <td>
        <a href="http://www.restosoft.com.ar/crm2/index.php?opcion=ampliar_cons&idresto='.$idresto.'&idampliar='.$idconsulta.'">Link para visualizar la tarea</a>
        </td>
        </tr>
        </table>');
        $mail->send(array($email));

        $email='sole@restosoft.com.ar';
        $mail = new htmlMimeMail5();
        $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
        $mail->setSubject('Nueva consulta');
        $mail->setText('Nueva consulta');
        $mail->setHTML('
        <table width="367" border="0" cellspacing="0" cellpadding="0">
        <tr>
        <td><span class="Estilo1">CLIENTE: ('.$idresto.' )  '.$sresto.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">CANAL: '.$scanal.' - OPER: '.$soper.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">------------ CONSULTA  --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$consulta.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">----------- RESPUESTAS --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$respuesta.'</span></td>
        </tr>
        <tr>
        <td>
        <a href="http://www.restosoft.com.ar/crm2/index.php?opcion=ampliar_cons&idresto='.$idresto.'&idampliar='.$idconsulta.'">Link para visualizar la tarea</a>
        </td>
        </tr>
        </table>');
        $mail->send(array($email));
        */

      };
      

      $opc="verconsultas";
      $seccion='consultas';
   };

   if ( $opc == "grabar_consulta"  ) {


      if (isSet($_REQUEST["x_idresto"])) {
      	$idresto = $_REQUEST["x_idresto"] ;
      } else {
        if (isSet($_REQUEST["x_idresto"])) {
      	  $idresto = $_REQUEST["x_idresto"] ;
      	};
      };
      
      if (isSet($_REQUEST["x_idconsulta"])) {
      	$idconsulta = $_REQUEST["x_idconsulta"] ;
      } else {
        if (isSet($_REQUEST["x_idconsulta"])) {
      	  $idconsulta = $_REQUEST["x_idconsulta"] ;
      	};
      };
      
      if (isSet($_REQUEST["x_consulta"])) {
      	$consulta = $_REQUEST["x_consulta"] ;
      } else {
        if (isSet($_REQUEST["x_consulta"])) {
      	  $consulta = $_REQUEST["x_consulta"] ;
      	};
      };
      
      if (isSet($_REQUEST["x_finalizado"])) {
      	$finalizado = $_REQUEST["x_finalizado"] ;
      };
      
      if (isSet($_REQUEST["x_respuesta"])) {
      	$x_respuesta = $_REQUEST["x_respuesta"] ;
      };
      
      if (isSet($_REQUEST["x_fecha"])) {
      	$fecha = $_REQUEST["x_fecha"] ;
      };
      
      if (isSet($_REQUEST["x_hora"])) {
      	$hora = $_REQUEST["x_hora"] ;
      };
      
      if (isSet($_REQUEST["x_oper"])) {
      	$oper = $_REQUEST["x_oper"] ;
      };


      $duracion=1;
      //$idoperador=$_SESSION["idoper"];

     //echo $finalizado." - ".$idresto." - ".$resto." - ".$idconsulta." - ".$fecha." - ".$hora." - ".$x_consulta." - ".$x_respuesta." - ".$idcanal;
     //echo "<br>";



     // Cada consulta ahora tiene una sola respuesta y mientras su estado sea Pendiente esta respuestas se puede
     // modificar o ampliar


     
     $SQL = "Update r_consultas Set  Respuesta='".$x_respuesta."' , Estado='".$finalizado."' ,IdOperador=".$oper ;
     $SQL = $SQL . " Where IdResto=".$idresto." and IdConsulta=".$idconsulta;
     //echo $SQL;
     //echo "<br>";
       
     $retid = mysql_query($SQL, $cid);
	 if (!$retid) {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"ERROR al grabar la consulta\");";
         echo "</script>";
      } else {
         echo "<script type=\"text/javascript\">";
         echo "alert(\"Consulta modificada !!\");";
         echo "</script>";
      }
	   
      /*
      $email='javiergmt@gmail.com';
      $resto='';
      $SQL = "Select NombreRest from r_resto Where Idresto =".$idresto;
      $retid = mysql_query($SQL, $cid);
      if ($retid) {
           $row = mysql_fetch_array($retid);
           $sresto = $row["NombreRest"];
      };
      
      require_once('../htmlMimeMail5.php');
      $email='javiergmt@gmail.com';
      $mail = new htmlMimeMail5();
      $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
      If ( $finalizado == 'F' ) {
        $mail->setSubject('Consulta Finalizada');
        $mail->setText('Consulta Finalizada');
      } else {
        $mail->setSubject('Consulta Modificada');
        $mail->setText('Consulta Modificada');
      }
        $mail->setCc('nmusso@gmail.com');
        $mail->setHTML('
        <table width="367" border="0" cellspacing="0" cellpadding="0">
        <tr>
        <td><span class="Estilo1">CLIENTE: ('.$idresto.' )  '.$sresto.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">------------ CONSULTA  --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$consulta.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">----------- RESPUESTAS --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$x_respuesta.'</span></td>
        </tr>
        <tr>
        <td>
        <a href="http://www.restosoft.com.ar/crm2/index.php?opcion=ampliar_cons&idresto='.$idresto.'&idampliar='.$idconsulta.'">Link para visualizar la tarea</a>
        </td>
        </tr>
        </table>');
        $mail->send(array($email));

      $email='sole@restosoft.com.ar';
      $mail = new htmlMimeMail5();
      $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
      If ( $finalizado == 'F' ) {
        $mail->setSubject('Consulta Finalizada');
        $mail->setText('Consulta Finalizada');
      } else {
        $mail->setSubject('Consulta Modificada');
        $mail->setText('Consulta Modificada');
      }
        //$mail->setCc('juli.mt92@gmail.com');
        $mail->setHTML('
        <table width="367" border="0" cellspacing="0" cellpadding="0">
        <tr>
        <td><span class="Estilo1">CLIENTE: ('.$idresto.' )  '.$sresto.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">------------ CONSULTA  --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$consulta.'</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">----------- RESPUESTAS --------------</span></td>
        </tr>
        <tr>
        <td><span class="Estilo1">'.$x_respuesta.'</span></td>
        </tr>
        <tr>
        <td>
        <a href="http://www.restosoft.com.ar/crm2/index.php?opcion=ampliar_cons&idresto='.$idresto.'&idampliar='.$idconsulta.'">Link para visualizar la tarea</a>
        </td>
        </tr>
        </table>');
        $mail->send(array($email));
      */

      $opc="verconsultas";
      $seccion='consultas';

     //echo $SQL;
     //echo "<br>";
   };
   
   if ( $opc == "notif_consulta"  ) {
   

   
       $SQL = " Select c.*,r.NombreRest as Resto,o.Nombre as Oper from r_consultas c ";
       $SQL = $SQL . " left outer join r_resto r on r.Idresto = c.IdResto ";
       $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
       $SQL = $SQL . " Where (Estado = 'P')";
       $SQL = $SQL . " order by c.IdConsulta DESC";
       
       //echo $SQL;
       //echo "<br>";
       
       $retid = mysql_query($SQL, $cid);

       if (!$retid) {
		echo("Error en la consulta");
       } else {
       



       //$html= '<table width="367" border="0" cellspacing="0" cellpadding="0">';
       
       $html='<table>';
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

        if ( $respuesta == '' ) { $respuesta = 'SIN RESPUESTA'; };
        
        $html=$html.'<tr>';

        $html=$html.'<td><span class="Estilo1">==============================</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1"> ('.$idresto.' )  '.$nombrerest.' - '.$oper.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">---------- CONSULTA  ------------</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">'.$consulta.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">--------- RESPUESTAS ------------</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td><span class="Estilo1">'.$respuesta.'</span></td>';
        $html=$html.'</tr>';
        $html=$html.'<tr>';
        $html=$html.'<td>';
        



       };
       $html=$html.'</tr></table>';
       

       require_once('../htmlMimeMail5.php');
       $email='javiergmt@gmail.com';
       $mail = new htmlMimeMail5();
       $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
       $mail->setSubject('Consultas Pendientes');
       $mail->setHTML($html);
       $mail->send(array($email));

       $email='msolepascual@gmail.com';
       $mail = new htmlMimeMail5();
       $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
       $mail->setSubject('Consultas Pendientes');
       $mail->setHTML($html);
       $mail->send(array($email));

       //echo $html;
       //echo "<br>";
       

       };
       
       
       // Envio mails a Operadores
       
       $SQL1 = " Select * From r_operador where Idoperador > 0";
       $retid1 = mysql_query($SQL1, $cid);
       
       if (!$retid1) {
		  echo("Error en la consulta");
       } else {
          While ($row1 = mysql_fetch_array($retid1)) {
              $x_oper = $row1["IdOperador"];
              $x_email = $row1["Email"];
              
              $SQL = " Select c.*,r.NombreRest as Resto,o.Nombre as Oper from r_consultas c ";
              $SQL = $SQL . " left outer join r_resto r on r.Idresto = c.IdResto ";
              $SQL = $SQL . " inner join r_operador o on o.IdOperador = c.IdOperador ";
              $SQL = $SQL . " Where (c.IdOperador =".$x_oper.") and (c.Estado = 'P')";
              $SQL = $SQL . " order by IdOperador,c.IdConsulta DESC";


              $retid = mysql_query($SQL, $cid);

              if (!$retid) {
		         echo("Error en la consulta");
              } else {

              $cons=0;
              $html='<table>';

              While ($row = mysql_fetch_array($retid)) {

                    $cons=$cons+1;
                    $idresto = $row["IdResto"];
                    $idconsulta = $row["IdConsulta"];
		            $nombrerest = $row["Resto"];
		            $fecha = $row["Fecha"];
		            $hora = $row["Hora"];
                    $estado = $row["Estado"];
                    $consulta = $row["Consulta"];
                    $oper = $row["Oper"];
                    $respuesta = $row["Respuesta"];

                    if ( $respuesta == '' ) { $respuesta = 'SIN RESPUESTA'; };

                    $html=$html.'<tr>';

                    $html=$html.'<td><span class="Estilo1">==============================</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1"> ('.$idresto.' )  '.$nombrerest.'</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1">FECHA: '.$fecha.' - HORA: '.$hora.'</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1">---------- CONSULTA  ------------</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1">'.$consulta.'</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1">--------- RESPUESTAS ------------</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td><span class="Estilo1">'.$respuesta.'</span></td>';
                    $html=$html.'</tr>';
                    $html=$html.'<tr>';
                    $html=$html.'<td>';
              }
              $html=$html.'</tr></table>';

              if ( $cons > 0 ) {
              
              //echo $x_email;
              //echo "<br>";

              require_once('../htmlMimeMail5.php');
              $mail = new htmlMimeMail5();
              $mail->setFrom('RestoSoft <info@restosoft.com.ar>');
              $mail->setSubject('Consultas Pendientes asignadas');
              $mail->setHTML($html);
              $mail->send(array($x_email));

              };

              };
          };
       };

       echo "<script type=\"text/javascript\">";
       echo "alert(\"Mails de Consultas Pendientes Enviado !!\");";
       echo "</script>";


       $opc="verconsultas";
       $seccion='consultas';


   };


?>

