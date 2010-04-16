<?php
  include 'top.php';
?>

<?php
  function isChecked($campo) {
    if ($campo == 1) {
      return 'value="1" checked="checked"';
    } else {
      return 'value="0"';
    }
  }

  if (isset($_SESSION['logado'])) {

    if ($_POST['write'] === 'checkbox') {

      if (!executeSQL("UPDATE configuracao_usuario SET portugues='" . $_POST['portugues'] . "'"
               . ", ingles=" . $_POST['ingles']
               . ", ocultar_lidos=" . $_POST['ocultar_lidos']
               . ", ordem_antigo_para_recente=" . $_POST['ordem_antigo_para_recente']
               . " WHERE id_usuario = '" . $_SESSION['email'] . "'"))
      {
        include 'erro-banco.php';
      }

    }

    $resultado = executeSQL("SELECT * FROM configuracao_usuario WHERE id_usuario = '" . $_SESSION['email'] . "'");

    if (mysql_num_rows($resultado) > 0) {

      while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
          $portugues = $row['portugues'];
          $ingles = $row['ingles'];
          $ordem_antigo_para_recente = $row['ordem_antigo_para_recente'];
          $ocultar_lidos = $row['ocultar_lidos'];
      }
    }
?>
  <p>
    <input type="checkbox" onclick="javascript:doConfiguracao('portugues')" id="portugues" <?php echo isChecked($portugues) ?> /> português
    &#32;
    <input type="checkbox" onclick="javascript:doConfiguracao('ingles')" id="ingles" <?php echo isChecked($ingles) ?> /> English
    <br/>
    <input type="checkbox" onclick="javascript:doConfiguracao('ordem_antigo_para_recente')" id="ordem_antigo_para_recente" <?php echo isChecked($ordem_antigo_para_recente) ?> /> Mais antigo primeiro
    <br/>
    <span title="Os favoritos não são ocultos"><input type="checkbox" onclick="javascript:doConfiguracao('ocultar_lidos')" id="ocultar_lidos" <?php echo isChecked($ocultar_lidos) ?> /> Ocultar os já lidos</span>
    <!--<br/>
    <input type="checkbox" onclick="javascript:doConfiguracao('agrupar_por_tipo')" id="agrupar_por_tipo" <?php echo isChecked($agrupar_por_tipo) ?> /> Agrupar por tipo de postagem
    <br/>
    <input type="checkbox" onclick="javascript:doConfiguracao('mostrar_apenas_favoritos')" id="mostrar_apenas_favoritos" <?php echo isChecked($mostrar_apenas_favoritos) ?> /> Mostrar só os favoritos
    -->
  </p>
  <!-- AINDA NÃO IMPLEMENTADO
  <p>
    Mostrar postagens de:&nbsp;
    <select>
      <option value="all">Todos</option>
      <option value="me">Felipe Lalli</option>
    </select>
  </p> -->

<?php
  }
?>

<?php
  include 'bottom.php';
?>