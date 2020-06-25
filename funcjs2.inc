<script language="JavaScript" type="text/JavaScript">

function pedirgrabarconsulta() {
  document.formconsultas.x_finalizado.value = "P";
  document.formconsultas.submit();
};

function pedirgrabarconsultafin() {
  document.formconsultas.x_finalizado.value = "F";
  document.formconsultas.submit();
};


function pedirampliar() {
  document.formconsultas.modoOp.value = "ampliar";
  document.formconsultas.submit();
};

function pedireditarcosnulta() {
  document.formconsultas.opcion.value = "editar_consulta";
  document.formconsultas.submit();
};


function pedirgenabono() {
  document.form_genclave.submit();
};

function pediragregar() {
  document.form_consultas.modoOp.value = "agregar";
  document.form_consultas.submit();
};


function pediragregarcli() {

  document.form_nuevocli.modoOp.value = "agregarcli";
  document.form_nuevocli.submit();
};

function pedirgrabarcliente() {
  document.form_editcli.submit();
};

function pedirgrabarequipo() {
  document.form_editequipo.submit();
};

function pediragregarequipo() {
  document.form_nuevoequipo.submit();
};

function pediragregarcont() {

  document.form_nuevocont.modoOp.value = "agregarcont";
  document.form_nuevocont.submit();
};

function pedircrear() {

  document.form_consultas.modoOp.value = "crear";
  document.form_consultas.submit();
};



function pedirbuscar() {

  document.formlistado.modoOp.value = "buscar";
  document.formlistado.submit();
};

function pedirbuscar_abono() {

  document.formabonos.modoOp.value = "buscar_abono";
  document.formabonos.submit();
};

function pedirbuscar_equipo() {

  document.formequipos.modoOp.value = "buscar_equipo";
  document.formequipos.submit();
};

function pedirborrar_equipo() {

  document.formequipos.modoOp.value = "borrar_equipo";
  document.formequipos.submit();
};

function pedirbuscarpendiente() {

  document.formacciones.modoOp.value = "buscar";
  document.formacciones.submit();
};

function pedirbuscarconsulta() {

  document.formacciones.modoOp.value = "buscar_ultima";
  document.formacciones.submit();
};

function pedirbuscarnuevo() {

  document.form_selec.modoOp.value = "buscarnuevo";
  document.form_selec.submit();
};

function pedircancelar() {

  document.formtar.modoOp.value = "cancelar";
  document.formtar.submit();
};

function pedirvalidar() {

  document.formtar.modoOp.value = "validar";
  document.formtar.submit();
};

function pedirbajar() {

  document.formtar.modoOp.value = "ok";
  document.formtar.submit();
};

function pediraceptar() {

  document.formlogin.modoOp.value = "login";
  document.formlogin.submit();

};

function pedirautoclave() {

  document.formautoclave.modoOp.value = "autoclave";
  document.formautoclave.submit();
};

function pedirborrar() {
  if (confirm("¿Seguro que desea eliminar?") == true) {
  	document.formtar.modoOp.value = "borrar";
  	document.formtar.submit();
  }else{
  	document.formtar.modoOp.value = "cancelar";
  	document.formtar.submit();
 }

};


function pedirgrabar() {
  var jmodo = "grabar";
  if ( Validar(document.formtar.x_fecha.value) == false)    {
  	   jmodo = "invalido";
       alert('Error en Fecha');
  };
  if ( document.formtar.x_nombre.value == '' )    {
  	   jmodo = "invalido";
       alert('El nombre no puede estar vacio');
  };
  if ( document.formtar.x_dni.value == '' )    {
  	   jmodo = "invalido";
       alert('El DNI no puede estar vacio');
  };
  document.formtar.modoOp.value = jmodo;
  //MM_openBrWindow('nada.htm','ftareas','width=220,height=70');
  document.formtar.submit();
};

</script>


