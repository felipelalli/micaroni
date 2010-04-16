<?php
  session_start();

  date_default_timezone_set("Europe/London");

  function executeSQL($sql) {
    // echo $sql; // para debug

    $conexao = mysql_connect('localhost', 'lost', 'brisbane');

    if (!$conexao) {
      include 'erro-banco.php';
    } else {
      //mysql_set_charset('utf8', $conexao);
      mysql_select_db('lost', $conexao);
      $ret = mysql_query($sql, $conexao);

      global $affected_rows;
      $GLOBALS['affected_rows'] = mysql_affected_rows();

      if (strripos($sql, "INSERT") !== false) {
        $GLOBALS['last_id'] = mysql_insert_id();
      }

      mysql_close($conexao);
    }

    return $ret;
  }

  function postagem_usuario($id, $id_user) {
      $sql = "SELECT * FROM postagem_usuario WHERE id_postagem = " . $id . " AND id_usuario = '" . $id_user . "'";
      $res2 = executeSQL($sql);

      if (mysql_num_rows($res2) == 0) {
        executeSQL("INSERT INTO postagem_usuario (id_postagem, id_usuario) VALUES (" . $id . ", '" . $id_user . "')");
      }

      $res2 = executeSQL($sql);
      $row2 = mysql_fetch_array($res2, MYSQL_ASSOC);

      return $row2;
  }

  function info_user($id) {
    $resultado = executeSQL(
        "SELECT * FROM usuario WHERE email = '" . $id . "'");

    $row = mysql_fetch_array($resultado, MYSQL_ASSOC);

    return $row;
  }

  function get_config_user($id) {
    $resultado = executeSQL("SELECT * FROM configuracao_usuario WHERE id_usuario='" . $id . "'");
    $row = mysql_fetch_array($resultado, MYSQL_ASSOC);

    return $row;
  }

  function cria_relacoes_inexistentes($id_user) {
    $result = executeSQL("SELECT * FROM postagem");

    while ($row = mysql_fetch_array($result, MYSQL_ASSOC)) {
      postagem_usuario($row['id'], $id_user); // cria se não existe
    }
  }

  function get_posts_in_order($id) {
    return get_posts_in_order_complete($id, false);
  }

  function get_posts_in_order_complete($id, $sem_lidos) {
    cria_relacoes_inexistentes($id);

    $config = get_config_user($id);

    if (is_null($config['id_postagem_aberta'])) {
      $id_aberto = "NULL";
    } else {
      $id_aberto = $config['id_postagem_aberta'];
    }

    if ($config['ocultar_lidos']) {
      $condicao = "AND (postagem_usuario.lido = 0 OR postagem.id = "
          . $id_aberto
          . " OR postagem_usuario.favorito = 1)";
    } else {
      $condicao = "";

      if ($sem_lidos) {
        $condicao = "AND (postagem_usuario.lido = 0)";
      }
    }

    $sql = "SELECT * FROM postagem, postagem_usuario WHERE postagem.id = postagem_usuario.id_postagem"
                    . " AND postagem_usuario.id_usuario = '" . $id . "' "
                    . $condicao
                    . " ORDER BY postagem.data_modificada " . ($config['ordem_antigo_para_recente']?"ASC":"DESC");

    // echo "SQL: " . $sql;

    $result = executeSQL($sql);

    return $result;
  }

  function go_to_first($id) {
    $result = get_posts_in_order_complete($id, true);

    if (mysql_num_rows($result) > 0) {
      $row = mysql_fetch_array($result, MYSQL_ASSOC);
      $sql = "UPDATE configuracao_usuario SET id_postagem_aberta=" . $row['id_postagem'] . " WHERE id_usuario='" . $id . "'";
      //echo $sql;
      executeSQL($sql);
    }
  }

  function go_to_next($id) {
    $config = get_config_user($id);
    $posts = get_posts_in_order($id);

    $achou = false;
    $sair = false;
    $registro = NULL;

    while (($row = mysql_fetch_array($posts, MYSQL_ASSOC)) && !$sair) {

      if ($achou) {
        $registro = $row['id'];
        $sair = true;
      } else if ($row['id'] === $config['id_postagem_aberta']) {
        $achou = true;
      }
    }

    if (is_null($registro)) {
      $registro = "NULL";
    }

    executeSQL("UPDATE configuracao_usuario SET id_postagem_aberta=" . $registro . " WHERE id_usuario='" . $id . "'");
  }

  function arruma_data($data, $fuso) {
    return $data + ($fuso * 60 * 60);
  }
?>