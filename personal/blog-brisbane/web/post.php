<?php
  include 'db.php';
?>

<html>
  <head>
    <title>Nova Postagem</title>
    <link rel="shortcut icon" href="img/icon.png">

    <meta http-equiv=content-type content="text/html; charset=UTF-8"/>
    <style type="text/css">
      @import "style.css";
      @import "post.css";
    </style>

    <script type="text/javascript" src="post.js"></script>
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
?>
      <h2>Nova postagem</h2>

      <form action="dopost.php" method="post">

        <div>
          Título: <input type="text" name="titulo" size=50 />
        </div>

        <div>
          <textarea name="texto" rows=20 cols=50>&lt;p&gt;

&lt;/p&gt;</textarea>
        </div>

        <input type="hidden" value="<?php echo $_SESSION['email'] ?>" name="autor"/>

        <div>
          Cidade: <input type="text" name="cidade" value="Brisbane"/>

          Língua: <select name="lingua">
<?php
            $resultado = executeSQL("SELECT * FROM lingua");

            while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
?>
              <option value="<?php echo $row['id']?>"><?php echo $row['descricao']?></option>
<?php
            }
?>
          </select>
        </div>

        <div>
          Fuso horário: <select name="fuso_horario">
              <option value="10">GMT+10 (Austrália, Brisbane)</option>
              <option value="-3">GMT-3 (Brasil, São Paulo)</option>
          </select>
        </div>

        <div>
          Clima: <select name="clima">
            <option value="0">&lt;selecione um clima&gt;</option>
<?php
            $resultado = executeSQL("SELECT * FROM clima");

            while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
?>
              <option value="<?php echo $row['id']?>"><?php echo $row['descricao']?></option>
<?php
            }
?>
          </select>
        </div>

        <div>
          Temperatura: <input type="text" name="temperatura" /> &#176;C
        </div>

        <div>
          Você está: <select name="humor">
            <option value="0">&lt;selecione um humor&gt;</option>
<?php
            $resultado = executeSQL("SELECT * FROM humor");

            while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
?>
              <option value="<?php echo $row['id']?>"><?php echo $row['descricao']?></option>
<?php
            }
?>
          </select>
        </div>

        <div>
          Tags:
          <input type="text" size=50 name="tagstexto" />
  <?php
              $resultado = executeSQL("SELECT nome_tag FROM tags_postagem group by nome_tag");

              while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
  ?>
                <a class="tag" onclick="javascript:seleciona('tagstexto', '<?php echo $row['nome_tag'] ?>')"><?php echo $row['nome_tag'] ?></a>
  <?php
              }
  ?>
        </div>

        <div>
            Disponível para:
            <input type="text" size=50 name="disponivelpara" />
  <?php
              $resultado = executeSQL("SELECT * FROM grupo");

              while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
  ?>
                <a class="tag" onclick="javascript:seleciona('disponivelpara', '<?php echo $row['descricao'] ?>')"><?php echo $row['descricao'] ?></a>
  <?php
              }
  ?>
        </div>

        <div>
          <input type="submit" value="Postar"/>
        </div>

      </form>

      <p><br/></p> <p><br/></p>

<?php
    }
  }
?>
    </div>
  </div> <!-- all -->

<?php
  include 'bottom.php';
?>