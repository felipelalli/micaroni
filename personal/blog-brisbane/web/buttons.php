<?php
  include 'top.php';
?>

<?php
  if (isset($_SESSION['logado'])) {
    $row = get_config_user($_SESSION['email']);

    if (!is_null($row['id_postagem_aberta'])) {

      if ($_POST['acao'] == 1) {
          $lido = "1";
      } else if ($_POST['acao'] == 2) {
          $lido = "0";
      }

      if ($_POST['acao'] == 1 || $_POST['acao'] == 2) {
          executeSQL("UPDATE postagem_usuario SET lido=" . $lido . " WHERE id_usuario='" . $_SESSION['email'] . "' AND id_postagem=" . $row['id_postagem_aberta']);
          go_to_next($_SESSION['email']);
          $row = get_config_user($_SESSION['email']);
      }
    } // not null

    if (!is_null($row['id_postagem_aberta'])) {

      $row2 = postagem_usuario($row['id_postagem_aberta'], $_SESSION['email']);
?>

<?php
  //if (!$row2['lido']) {
?>
  <input type="button" class="button" title="Clique aqui se já terminou de ler" onclick="javascript:botaoAcao(1)" value="Marcar como lido"/>
<?php
  //}
?>

  <input type="button" class="button2" title="Clique aqui se não conseguiu ler tudo" onclick="javascript:botaoAcao(2)" value="Terminar de ler depois"/>

<?php
    } // postagem aberta
  } // logado
?>

<?php
  include 'bottom.php';
?>