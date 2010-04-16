<?php
  include 'db.php';
?>

<html>
  <head>
    <title>Postando...</title>
    <link rel="shortcut icon" href="img/icon.png">

    <meta http-equiv=content-type content="text/html; charset=UTF-8"/>
    <style type="text/css">
      @import "style.css";
    </style>
  </head>
  <body>
  <div id="all">
    <div id="posting">

<?php
  if (!isset($_SESSION['logado'])) {
?>
    Você não está logado!
<?php
  } else {
    if ($_SESSION['email'] === 'micaroni@gmail.com') {

        //$texto = htmlspecialchars($_POST['texto']);
        //$texto = str_replace("\n", "<br/>", $texto);
        //$texto = str_replace("\r", "", $texto);
        $texto = $_POST['texto'];

        $sql = "INSERT INTO postagem (id_autor, cidade, data_publicacao, data_modificada, id_clima, temperatura, id_humor, texto, rascunho, id_lingua, titulo, fuso_horario) VALUES"
            . " ('" . $_POST['autor'] . "'"
            . ", '" . $_POST['cidade'] . "'"
            . ", " . time() . ""
            . ", " . time() . ""
            . ", " . ($_POST['clima'] == 0?"NULL":$_POST['clima']) . ""
            . ", " . ($_POST['temperatura'] === ""?"NULL":$_POST['temperatura']) . ""
            . ", " . ($_POST['humor'] == 0?"NULL":$_POST['humor']) . ""
            . ", '" . $texto . "'"
            . ", 0"
            . ", " . ($_POST['lingua'] == 0?"NULL":$_POST['lingua'])
            . ", '" . $_POST['titulo'] . "'"
            . ", " . $_POST['fuso_horario']
            . ")";

        //echo "SQL: " . $sql;

        if (!executeSQL($sql)) {
          include 'erro-banco.php';
        } else {
          $novo_id = $last_id;

          $resultado = executeSQL("SELECT * FROM grupo");

          while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
            $key = '[' . $row['descricao'] . '] ';

            if (strpos($_POST['disponivelpara'], $key) !== false) {
              $sql = "INSERT INTO postagem_grupo (id_postagem, id_grupo) VALUES (" . $novo_id . ", " . $row['id'] . ")";
              //echo "sql=" . $sql;
              executeSQL($sql);
            }
          }

          $resultado = executeSQL("SELECT nome_tag FROM tags_postagem group by nome_tag");

          while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
            $key = '[' . $row['nome_tag'] . '] ';

            if (strpos($_POST['tagstexto'], $key) !== false) {
              $sql = "INSERT INTO tags_postagem (id_postagem, nome_tag) VALUES (" . $novo_id . ", '" . $row['nome_tag'] . "')";
              //echo "sql=" . $sql;
              executeSQL($sql);
            }
          }

?>
          <p><b><big>Postado com sucesso!</big></b></p>
          <p><a href="post.php">Postar novamente?</a></p>
<?php
      } // sucesso
    } // micaroni
  } // logado
?>
    </div>
  </div> <!-- all -->

<?php
  include 'bottom.php';
?>