<?
  echo "<table summary=\"Equipos\">";
  echo "<form name=\"form_genabonos\" method=\"post\" action=\"index.php?opcion=grabarclaves\">";
  
  echo "<ul><li>MES:</li></ul>";
  echo "<select name=\"x_mesclave\" style=\"BACKGROUND-COLOR: #FFFFFF; FONT-FAMILY:arial; FONT-SIZE: 10px\" class=\"campos3\">";
            echo "<option value='1' >ENERO</option>";
            echo "<option value='2' >FEBRERO</option>";
            echo "<option value='3' >MARZO</option>";
            echo "<option value='4' >ABRIL</option>";
            echo "<option value='5' >MAYO</option>";
            echo "<option value='6' >JUNIO</option>";
            echo "<option value='7' >JULIO</option>";
            echo "<option value='8' >AGOSTO</option>";
            echo "<option value='9' >SEPTIEMBRE</option>";
            echo "<option value='10' >OCTUBRE</option>";
            echo "<option value='11' >NOVIEMBRE</option>";
            echo "<option value='12' >DICIEMBRE</option>";
            echo "</select>";
  
  echo "<ul><li>&nbsp;</li></ul>";
  
  echo "<ul><li>MES:</li></ul>";
  echo "<select name=\"x_anoclave\" style=\"BACKGROUND-COLOR: #FFFFFF; FONT-FAMILY:arial; FONT-SIZE: 10px\" class=\"campos3\">";
            echo "<option value='2018' >2018</option>";
            echo "<option value='2019' >2019</option>";
            echo "<option value='2020' >2020</option>";
            echo "<option value='2021' >2021</option>";
            echo "<option value='2022' >2022</option>";
            echo "</select>";
  echo "<ul><li>&nbsp;</li></ul>";
  
  echo "<ul><li>";
  echo "<a href=\"#\" onClick=\"javascript:pedirgenabonos()\"><img src=\"images/boton_grabar.jpg\" width=\"70\" height=\"22\" border=\"0\"></a>";
  echo "</li></ul>";


   echo "</form>";
   echo "</table>";
 ?>

