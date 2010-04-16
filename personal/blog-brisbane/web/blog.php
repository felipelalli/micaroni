<?php include 'db.php' ?>

<?php
  if (isset($_SESSION['logado'])) {
    if (isset($_GET['id'])) {
      executeSQL("UPDATE configuracao_usuario SET id_postagem_aberta=" . $_GET['id'] . " WHERE id_usuario='" . $_SESSION['email'] . "'");
    }
  }

  include 'index.html';
?>