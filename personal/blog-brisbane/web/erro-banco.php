<div id="error-sql">
<?php
  if (strcmp(mysql_error(), '') == 0) {
?>
    <p>Operação inválida!</p>
<?php
  } else {
?>
  <p>Erro ao acessar banco de dados:
<?php
    echo mysql_error();
?>
  </p>
  <p>
    Por favor, informe este erro para mim: <a href="mailto:micaroni@gmail.com">micaroni@gmail.com</a>
  </p>
<?php
  }
?>
</div>