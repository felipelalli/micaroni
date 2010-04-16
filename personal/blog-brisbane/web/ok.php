<?php
  include 'top.php';
?>

<head>
  <title>Lalli Lost in Brisbane</title>
  <link rel="shortcut icon" href="img/icon.png">

  <meta http-equiv=content-type content="text/html; charset=UTF-8"/>
  <style type="text/css">
    @import "_global.css";
    @import "ok.css";
  </style>
</head>
<body>
  <div id="message">
  <?php

    $email = $_GET["email"];
    $confirmacao = $_GET["confirmacao"];

    if (!executeSQL("UPDATE usuario SET email_verificado=1, data_cadastro="
        . time()
        . " WHERE email='"
        . $email . "' AND codigo_verificacao=" . $confirmacao))
    {
      include 'erro-banco.php';
    } else {

      if ($GLOBALS['affected_rows'] == 0) {
  ?>
        <p>Código de confirmação inválido!</p>
        <p>Tente fazer um novo cadastro ou tente copiar a URL do email
        e colar diretamente no navegador.</p>
  <?php
      } else {
  ?>
        <p>Email verificado com sucesso! Agora você já pode fazer login no blog.</p>
        <p>
          <a href="index.html">&gt;&gt; Ir para o blog <b>Lalli Lost in Brisbane</b></a>
        </p>
  <?php
      }
    }
  ?>

  </div>
</body>

<?php
  include 'bottom.php';
?>