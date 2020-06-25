<?php
   //Inicio la sesi�n

   session_start();
   
   /*
   if ($_SESSION) {
   print_r ($_SESSION);
   
	}
   */
   
   //Si es creaci�n de sesi�n inicializo las variables
   
   //If (!IsSet($_SESSION["iniciada"])) {
   
   //$_SESSION['usuario'] = "VOID";
   
   If (!IsSet($_SESSION)) {
   
      //$idsesion=session_id();
      
      //$_SESSION["Id_Sesion"]=$idsesion;
  	
      //$_SESSION["datos_conexion"] = $datos_conexion;	
  
		    
      $ini = true;
      //session_register("iniciada");
      $_SESSION["iniciada"] = $ini;
      $_SESSION['usuario'] = "VOID";
	
     };

	function fetchip() {
	//get useful vars:
	if (isset($_SERVER["HTTP_CLIENT_IP"])) {
	   $client_ip = $_SERVER["HTTP_CLIENT_IP"];
	} else {
	   $client_ip="";
	}   	   
	if (isSet($_SERVER["HTTP_X_FORWARDED_FOR"])) {
		$x_forwarded_for = $_SERVER["HTTP_X_FORWARDED_FOR"];
	};
	$remote_addr = $_SERVER["REMOTE_ADDR"];
	// then the script itself
	if (!empty ($client_ip) ) {
	$ip_expl = explode(".",$client_ip);
	$referer = explode(".",$remote_addr);
	if($referer[0] != $ip_expl[0]) {
	$ip=array_reverse($ip_expl);
	$return=implode(".",$ip);
	} else {
	$return = $client_ip;
	};
	} elseif (!empty($x_forwarded_for) ) {
	if(strstr($x_forwarded_for,',')) {
	$ip_expl = explode(',',$x_forwarded_for);
	$return = end($ip_expl);
	} else {
	$return = $x_forwarded_for;
	};
	} else {
	$return = $remote_addr;
	};
	unset ($client_ip,$x_forwarded_for,$remote_addr,$ip_expl);
	return ( $return );
	};
  	
      
?>
