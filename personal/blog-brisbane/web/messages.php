<?php
  include 'top.php';
?>

<?php
  if (isset($_SESSION['logado'])) {

    $postagem_aberta_res = executeSQL("SELECT id_postagem_aberta FROM configuracao_usuario WHERE id_usuario='" . $_SESSION['email'] . "'");
    $row_postagem_aberta = mysql_fetch_array($postagem_aberta_res, MYSQL_ASSOC);
?>

<?php
    //for ($i = 1; $i <= 100; $i++) {
    $resultado = get_posts_in_order($_SESSION['email']);

    if (mysql_num_rows($resultado) == 0) {
?>
      <i>Não há nada aqui. Tente mudar os filtros.</i>
<?php
    } else {
  ?>
      <ul>
  <?php
      while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {

        $data_arrumada = arruma_data($row['data_modificada'], $row['fuso_horario']);

        $row2 = postagem_usuario($row['id'], $_SESSION['email']);

        if ($row_postagem_aberta['id_postagem_aberta'] === $row['id']) {
  ?>
          <li class="liselec">
  <?php
        } else if ($row2['favorito']) {
  ?>
          <li class="lifav">
  <?php
        } else if ($row2['lido']) {
  ?>
          <li class="li3">
  <?php
        } else {
  ?>
          <li>
  <?php
        }

        if ($row_postagem_aberta['id_postagem_aberta'] === $row['id']) {
  ?>
          <span class="selected">
  <?php
        } else if ($row2['lido']) {
  ?>
          <span class="readed">
  <?php
        } else if ($row2['aberto']) {
  ?>
          <span class="notfinished">
  <?php
        } else {
  ?>
          <span class="notreaded">
  <?php
        }
  ?>
        <a title="<?php echo date('g:i a', $data_arrumada) ?>" href="javascript:goToPost(<?php echo $row['id'] ?>)"><span class="date"><?php echo date('d/M/Y', $data_arrumada) ?></span> <?php echo $row['titulo'] ?></a></span>

  <?php
      }
  ?>
    </ul>

<?php
    } // se há resultados
  }
?>

<?php
  include 'bottom.php';
?>