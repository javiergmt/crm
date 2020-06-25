<script language="JavaScript" type="text/JavaScript">

function pedirgrabarconsulta() {
  document.formconsultas.x_finalizado.value = "P";
  document.formconsultas.submit();
};

function pedirgrabarconsultafin() {
  document.formconsultas.x_finalizado.value = "F";
  document.formconsultas.submit();
};

function pedirgrabarconsultanueva() {
  document.formnuevaconsulta.submit();
};

function pedirgrabarequipo() {
  document.formequipoedit.opcion.value = "grabar_equipo";
  document.formequipoedit.submit();
};

function pedirborrarequipo() {
  document.formequipoedit.opcion.value = "borrar_equipo";
  document.formequipoedit.submit();
};

function pedireditarcliente() {
  document.formclientes.opcion.value = "editar_cli";
  document.formclientes.submit();
};

function pedirdesactcliente() {
  document.formclientes.opcion.value = "desactivar_cli";
  document.formclientes.submit();
};

function pedirgrabarcliente() {
  document.formcliedit.opcion.value = "grabarcli";
  document.formcliedit.submit();
};

function pedirampliarcliente() {
  document.formcliedit.opcion.value = "ampliar_cli";
  document.formcliedit.submit();
  
};

function pedirenviaremailcli() {
  document.formclientes.opcion.value = "enviaremailcli";
  document.formclientes.submit();

};


function pedirgenabonos() {
  document.form_genabonos.submit();
};



</script>


