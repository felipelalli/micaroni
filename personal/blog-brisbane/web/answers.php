<?php
  include 'top.php';
?>

<?php
  if (isset($_SESSION['logado'])) {
    $row = get_config_user($_SESSION['email']);

    $id_msg = $row['id_postagem_aberta'];

    if (!is_null($id_msg)) {
?>


<?php
    } // postagem aberta
  } // logado
?>

<?php
  include 'bottom.php';
?>