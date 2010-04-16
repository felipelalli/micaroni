<?php
  include 'top.php';
?>

<?php
  if (isset($_SESSION['logado'])) {

    $resultado = executeSQL("SELECT id_postagem_aberta FROM configuracao_usuario WHERE id_usuario='" . $_SESSION['email'] . "'");
    $row = mysql_fetch_array($resultado, MYSQL_ASSOC);

    if (!is_null($row['id_postagem_aberta'])) {

      $row_postagem_aberta = postagem_usuario($row['id_postagem_aberta'], $_SESSION['email']);

      if (isset($_POST['fav'])) {
        if ($_POST['fav'] === 'on') {
          $sql = "UPDATE postagem_usuario SET favorito=1 WHERE id_usuario='" . $_SESSION['email'] . "' AND id_postagem=" . $row['id_postagem_aberta'];
          executeSQL($sql);
        } else if ($_POST['fav'] === 'off') {
          executeSQL("UPDATE postagem_usuario SET favorito=0 WHERE id_usuario='" . $_SESSION['email'] . "' AND id_postagem=" . $row['id_postagem_aberta']);
        }
      }

      $row_postagem_aberta = postagem_usuario($row['id_postagem_aberta'], $_SESSION['email']);

?>

<?php
  if ($row_postagem_aberta['favorito']) {
?>
  <img onclick="javascript:changeFav('off')" title="Favorito!" src="img/fav-on.png"/>
<?php
  } else {
?>
  <img onclick="javascript:changeFav('on')" title="Favorito?" src="img/fav-off.png"/>
<?php
  }
?>

<?php
    } // tem postagem aberta
  } // logado
?>

<?php
  include 'bottom.php';
?>