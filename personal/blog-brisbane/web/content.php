<?php
  include 'top.php';
?>

<?php

  unset($email_verificado);

  if (isset($_POST["logoff"])?strcmp($_POST["logoff"], "true") == 0:false) {

    unset($_SESSION['logado']);

  } else if (strcmp($_POST["email"], "") != 0 && strcmp($_POST["password"], "") != 0) {

    $_SESSION['email'] = trim($_POST["email"]);

    $resultado = executeSQL(
        "SELECT apelido, email_verificado FROM usuario WHERE email = '"
          . trim($_POST["email"])
          . "' AND senha_md5 = '"
          . md5(trim($_POST["password"])) . "'");

    if (mysql_num_rows($resultado) == 0) {
      $usuario_errado = true;

    } else {
      $usuario_errado = false;

      while ($row = mysql_fetch_array($resultado, MYSQL_ASSOC)) {
          $_SESSION['apelido'] = $row['apelido'];
          $email_verificado = $row['email_verificado'];
      }

      if ($email_verificado == 1) {
        $_SESSION['logado'] = true;
        go_to_first($_SESSION['email']);
      }
    }
  }

  if (!isset($_SESSION['logado'])) {
?>
      <div id="error">

<?php
    if (!$usuario_errado && !isset($email_verificado)) {
?>
        <p>
          <p><b><big>Seja bem vindo!</big></b></p>
          <p><span class="ok-message">Para poder ler este blog é necessário fazer login.</span></p>
        </p>
<?php
    } else if ($usuario_errado) { // $usuario_errado
?>
        <p>
          <span class="error-message">
            Email e senha não correspondem!
          </span>
          <br/><a title="Clique aqui para se cadastrar" href="javascript:newuser(document.getElementById('email').value)"><br/>Cadastre-se aqui...</a>
        </p>
<?php
    } else if (!$email_verificado) {
?>
        <p>
          <span class="error-message">
            O seu email foi cadastrado mas ainda não foi verificado. Caso
            ainda não tenha recebido o email de confirmação tente fazer um
            novo cadastro.
          </span>
          <br/><a title="Novo cadastro" href="javascript:newuser(document.getElementById('email').value)"><br/>Clique aqui para tentar um novo cadastro...</a>
        </p>
<?php
    }
?>

        <form action="javascript:login(document.getElementById('email').value, document.getElementById('password').value)">
          <center> <!-- IE hack -->
            <table>
              <tr>
                <td class="right">email:</td>
                <td><input class="field" type="text" id="email" value="<?php echo $_SESSION['email'] ?>" /></td>
              </tr>
              <tr>
                <td class="right">senha:</td>
                <td><input class="field" type="password" id="password" /></td>
              </tr>
              <!--<tr>
                <td></td>
                <td class="right"><span title="Não selecione esta opção em computadores públicos">
                <input type="checkbox" id="manterlogado" /></span> Manter logado</td>
              </tr> * AINDA NÃO IMPLEMENTADO * -->
              <tr>
                <td></td>
                <td class="right"><button type="submit" class="button-login">Login</button></td>
              </tr>
            </table>
          </center>
        </form>

        <div id="newuser">
          <p><a title="Clique aqui para criar se cadastrar" href="javascript:newuser(document.getElementById('email').value)">Ainda não se cadastrou no blog?</a></p>
          <!-- <p><small><a href="#">Esqueci a senha</a></small></p>-->
        </div>
      </div>

<?php
  } else { // está logado

    if (isset($_POST['open'])) {
      executeSQL("UPDATE configuracao_usuario SET id_postagem_aberta=" . $_POST['open'] . " WHERE id_usuario='" . $_SESSION['email'] . "'");
    }

    $res = executeSQL("SELECT id_postagem_aberta FROM configuracao_usuario WHERE id_usuario='" . $_SESSION['email'] . "'");
    $row = mysql_fetch_array($res, MYSQL_ASSOC);

    if (is_null($row['id_postagem_aberta'])) {
?>
        <div id="nothing">
          <p>Selecione uma mensagem no menu ao lado esquerdo.</p>
        </div>

        <p>
          <a target=_blank href="http://www.flickr.com/photos/burningimage/2376276631/" title="Brisbane Sunset por Burning Image, no Flickr"><img src="http://farm3.static.flickr.com/2222/2376276631_6f224ee610.jpg" width="500" height="334" alt="Brisbane Sunset" /></a>
        </p>

        <p>
          Pôr do sol em Brisbane, QLD, AUS
        </p>

<?php
    } else {
        $res_postagem = executeSQL("SELECT * FROM postagem WHERE id=" . $row['id_postagem_aberta']);

        if (mysql_num_rows($res_postagem) == 0) {
?>
          <div id="nothing">
            <p>Ops! Esta postagem não existe mais?</p>
          </div>
<?php
        } else {
          $row_postagem = mysql_fetch_array($res_postagem, MYSQL_ASSOC);

          $data_arrumada = arruma_data($row_postagem['data_modificada'], $row_postagem['fuso_horario']);
          $autor_info = info_user($row_postagem['id_autor']);

          postagem_usuario($row_postagem['id'], $_SESSION['email']);
          executeSQL("UPDATE postagem_usuario SET aberto=1 WHERE id_usuario='" . $_SESSION['email'] . "' AND id_postagem=" . $row_postagem['id']);
?>

<div id="data_postagem"><?php echo $row_postagem['cidade'] ?>, <?php echo date("F j, Y", $data_arrumada) ?></div>
<div id="titulo_postagem"><?php echo $row_postagem['titulo'] ?></div>

<?php echo $row_postagem['texto'] ?>

<div id="info">
  <p>
    Postado por <a title="<?php echo $autor_info['email'] ?>" href="mailto:<?php echo $autor_info['email'] ?>"><?php echo $autor_info['apelido'] ?></a> em <a title="Clique com o botão direito -> copiar URL para obter um link direto a esta mensagem" href="<?php echo 'http://' . $_SERVER['SERVER_NAME'] . '/lost/blog.php?id=' . $row_postagem['id'] ?>"><?php echo date('d/M/Y', $data_arrumada) ?> às <?php echo date("g:i a", $data_arrumada) ?> GMT<?php echo (($row_postagem['fuso_horario'] >= 0)?("+" . $row_postagem['fuso_horario']):$row_postagem['fuso_horario']) ?></a>.
  </p>

</div>

<?php
      } // id correto
    } // tem postagem selecionada
  } // está logado
?>

<?php
  include 'bottom.php';
?>