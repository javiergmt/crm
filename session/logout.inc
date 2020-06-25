<?php
	session_start();
	$prev = $_SESSION["Id_Sesion"];
	
	$_SESSION = array();
	session_destroy();
	$_SESSION["PrevSession"] = $prev;
	$usuario='X';
	$opc='menu�;
?>


