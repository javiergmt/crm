<?php
	function conectar($servidor,$usuario,$password) {
		return mysql_connect($servidor,$usuario,$password);
	};	
	
	function openQuery($SQL, $conexion) {
		return mysql_query($SQL, $conexion);
	};
	
	function proximo ($recordSet) {
		return mysql_fetch_array($recordSet);
	};
	
	function selDB ($db, $conexion) {
		return mysql_select_db ($db, $conexion);
	};
	
	function queryDB($sql, $conexion) {
		return mysql_query($sql, $conexion); 
	};
	
	//////////////////////////////////////////////////// 
	//Convierte fecha de mysql a normal 
	//////////////////////////////////////////////////// 
	function cambiaf_a_normal($fecha){ 
   	 ereg( "([0-9]{2,4})-([0-9]{1,2})-([0-9]{1,2})", $fecha, $mifecha); 
    	$lafecha=$mifecha[3]."/".$mifecha[2]."/".$mifecha[1]; 
    	return $lafecha; 
	}; 

	//////////////////////////////////////////////////// 
	//Convierte fecha de normal a mysql 
	//////////////////////////////////////////////////// 
	
	function cambiaf_a_mysql($fecha){ 
	    ereg( "([0-9]{1,2})/([0-9]{1,2})/([0-9]{2,4})", $fecha, $mifecha); 
	    $lafecha=$mifecha[3]."-".$mifecha[2]."-".$mifecha[1]; 
	    return $lafecha; 
	}; 
 
   /*
   Ejemplos
    
   <input type="text" name="fecha" value="<?echo cambiaf_a_normal($fila->fecha);?>"> 

   mysql_query ("insert into documento (titulo_documento, fecha_documento, cuerpo_documento) values ('$titulo_documento', '" . cambiaf_a_mysql($fecha) . "', '$cuerpo_documento')"); 
	*/

?>