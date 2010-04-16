<?php
  include 'top.php';
?>

<?php
  if (!isset($_SESSION['logado'])) {
?>
<!-- Não fez login ainda -->

<?php
  } else {
?>
    Seja bem vindo <span title="<?php print $_SESSION['email'] ?>"><big><?php print $_SESSION['apelido'] ?>!</big></span>

    <br/><a href="javascript:logoff()">Fazer logoff...</a>
<?php
    if ($_SESSION['email'] === 'micaroni@gmail.com') {
?>
    <br/><a target="_blank" href="post.php">Nova postagem...</a>
<?php
    }
?>

<?php
  }
?>

<?php
  include 'bottom.php';
?>