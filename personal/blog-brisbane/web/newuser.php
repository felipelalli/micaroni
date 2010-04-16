<?php
  include 'top.php';
?>

  <div id="newuser-form">
        <p>
          <span class="login-title">
            Novo usuário
          </span>
        </p>

<?php
  $cadastrou = false;

  $erro_email = false;
  $erro_pass = false;
  $erro_apelido = false;

  if ($_POST['try'] === 'on') {

    if (trim($_POST['email']) === '') {
      $erro_email = true;
    }

    if (trim($_POST['password']) === '' || trim($_POST['password2']) === ''
        || (strcmp(trim($_POST['password']), trim($_POST['password2'])) != 0)
        || (strlen(trim($_POST['password'])) < 3))
    {
      $erro_pass = true;
    }

    if (trim($_POST['apelido']) === '') {
      $erro_apelido = true;
    }

    if ($erro_apelido || $erro_email) {
?>
      <div id="error"><p><span class="error-message">Por favor, preencha todos os campos.</p></span></div>
<?php
    } else if ($erro_pass) {
?>
      <div id="error"><p><span class="error-message">A senha não foi digitada corretamente!</p></span></div>
<?php
    } else {

      $resultado = executeSQL(
          "SELECT apelido FROM usuario WHERE email = '"
            . trim($_POST["email"]) . "' AND email_verificado = 0");

      if (mysql_num_rows($resultado) > 0) {
        executeSQL("DELETE FROM usuario WHERE email = '" . trim($_POST["email"] . "'"));
      }

      // não deu nenhum erro até agora!

      $confirmacao = rand(1000000, 9999999);

      if (!executeSQL("INSERT INTO usuario (email, senha_md5, email_verificado, data_cadastro, apelido, codigo_verificacao) VALUES ('"
          . trim($_POST['email']) . "', '" . md5(trim($_POST['password'])) . "', " . "0," . time()
          . ", '" . trim($_POST['apelido']) . "' ," . $confirmacao . ")"))
      {
        include 'erro-banco.php';
      } else {
        if (mail(trim($_POST['email']),
            "Confirmação de email: Lalli Lost in Brisbane",
            "Olá " . trim($_POST['apelido']) . "!\r\n\r\nVocê está recebendo este email porque acabou de se cadastrar no blog"
            . " Lalli Lost in Brisbane. Caso não tenha feito nenhum cadastro, por favor"
            . " ignore este email.\r\n\r\nPara confirmar o seu cadastro entre na seguinte URL:\r\n"
            . "http://" . $_SERVER['SERVER_NAME'] . "/lost/ok.php?email="
            . trim($_POST['email']) . "&confirmacao=" . $confirmacao,
            "From: Lalli Lost in Brisbane <micaroni@gmail.com>; Content-Type: text/html; charset=utf-8"))
        {
  ?>
          <div id="error"><p><span class="ok-message">Um email foi enviado para <b><?php echo trim($_POST['email']) ?></b>
          com um código de confirmação. Abra seu email e clique no link recebido.</span></p></div>

          <input type="hidden" id="email" value="<?php echo $_POST['email'] ?>" />
          <input type="hidden" id="password" value="<?php echo $_POST['password'] ?>" />

  <?php
          $cadastrou = true;

          // configuração:

          executeSQL("INSERT INTO configuracao_usuario (id_usuario) VALUES ('" . trim($_POST['email']) . "')");

        } else {

          executeSQL("DELETE FROM usuario WHERE email = '" . trim($_POST["email"] . "'"));
  ?>
          <div id="error"><p><span class="error-message">Ocorreu algum erro ao enviar seu email de confirmação!
          Por favor tente novamente mais tarde. O usuário <b>não</b> foi cadastrado!</span></p></div>

  <?php
        }
      }
    }
  }

  if (!$cadastrou) {
    // verifica se usuário já existe
    if (strcmp($_POST["email"], "") != 0) {
      $resultado = executeSQL(
          "SELECT apelido, email_verificado FROM usuario WHERE email = '"
            . trim($_POST["email"]) . "'");

      if (mysql_num_rows($resultado) > 0) {
?>
        <p><i>Obs.: este email já está cadastrado!<br/>Volte para a tela de login e faça seu login.</i></p>
<?php
      }
    }
?>
        <form action="javascript:createuser(document.getElementById('email').value, document.getElementById('password').value, document.getElementById('password2').value, document.getElementById('apelido').value)">
          <center> <!-- IE hack -->
            <table>
              <tr>
                <td class="right">email:</td>
                <td><input class="field<?php echo ($erro_email?'-error':'') ?>" type="text" id="email" value="<?php echo $_POST['email'] ?>" /></td>
              </tr>
              <tr>
                <td class="right">senha:</td>
                <td><input class="field<?php echo ($erro_pass?'-error':'') ?>" type="password" id="password" /></td>
              </tr>
              <tr>
                <td class="right">confirmar senha:</td>
                <td><input class="field<?php echo ($erro_pass?'-error':'') ?>" type="password" id="password2" /></td>
              </tr>
              <tr>
                <td class="right">nome ou apelido:</td>
                <td><input title="Pode conter espaços" class="field<?php echo ($erro_apelido?'-error':'') ?>" type="text" id="apelido" value="<?php echo $_POST['apelido'] ?>" /></td>
              </tr>
              <tr>
                <td></td>
                <td class="right"><button type="submit" class="button-newuser">Vamos lá!</button></td>
              </tr>
            </table>
          </center>
        </form>
<?php
  }
?>

        <div id="newuser">
          <p><a href="javascript:login(document.getElementById('email').value, document.getElementById('password').value)"><?php if ($cadastrou) { ?> <center>Tentar fazer login...</center> <?php } else { ?> &lt;&lt; Voltar para tela de login <?php } ?> </a></p>
          <!-- <p><small><a href="#">Esqueci a senha</a></small></p>-->
        </div>
    </div>

<?php
  include 'bottom.php';
?>