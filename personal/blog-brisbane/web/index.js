function preload(){
    var nomes = new Array("img/bullet2.png", "img/bullet3.png",
                          "img/bullet.png", "img/bullet-fav.png",
                          "img/bullet-selected.gif", "img/fav-off.png",
                          "img/fav-on.png", "img/loading.gif",
                          "img/loading-star.png", "img/sep.png",
                          "img/shadow.png");

    var images = new Array(nomes.length);

    for (i = 0; i < nomes.length; i++) {    
        images[i] = new Image();
        images[i].src = nomes[i];
    }
}

function doAjax(url, id, values) {
    doAjaxComplete(url, id, values, true);
}

function doAjaxComplete(url, id, values, assync) {

    var http_request = false;
    var elemento = document.getElementById(id);
    
    if (document.getElementById('content') == elemento) {
        elemento.innerHTML = '<img title="loading ' + id + '..." alt="loading..." src="img/loading.gif"/>';
    }

    http_request = false;

    if (window.XMLHttpRequest) { // Mozilla, Safari,...
        http_request = new XMLHttpRequest();
        
        if (http_request.overrideMimeType) {
            http_request.overrideMimeType('text/xml');
        }
    } else if (window.ActiveXObject) { // IE
        try {
            http_request = new ActiveXObject("Msxml2.XMLHTTP");
        } catch (e) {
            try {
                http_request = new ActiveXObject("Microsoft.XMLHTTP");
            } catch (e) {}
        }
    }

    if (!http_request) {
        elemento.innerHTML = "No ajax :(";
        return false;
    } else {    
        http_request.onreadystatechange = function() { answer(http_request, elemento); };        

        http_request.open('POST', url, assync);

        http_request.setRequestHeader("Cache-Control",
                                       "no-store, no-cache, must-revalidate");

        http_request.setRequestHeader("Cache-Control",
                                      "post-check=0, pre-check=0");

        http_request.setRequestHeader("Pragma", "no-cache");


        http_request.setRequestHeader('Content-Type',
                                   "application/x-www-form-urlencoded; charset=utf-8");

        http_request.send(values);
    }
}

function answer(http_request, elemento) {

    if (http_request.readyState == 4) {    
        if (http_request.status == 200) {
            elemento.innerHTML = http_request.responseText;

            if (document.getElementById('content') == elemento) {
                loadAllAfter();
            }
        } else {
            document.getElementById('content').innerHTML = 'Algo deu errado... Erro: ' + http_request.status
                    + '<br/>Verifique sua conexão e <a href="javascript:window.location.reload()">tente recarregar a página</a>.';

            if (document.getElementById('content') != elemento) {
                elemento.innerHTML = "";
            }
        }
    }
}

function loadAllAfter() {
    loadAllFull(false);
}

function loadAll() {    
    loadAllFull(true);
}

function loadAllFull(contentToo) {    
    doAjax('footer.php', 'footer', null);
    doAjax('star.php', 'star', null);
    doAjax('buttons.php', 'buttons', null);
    doAjax('answers.php', 'answers', null);
    doAjax('organization-messages.php', 'organization-messages', null);
    doAjax('messages.php', 'messages', null);
    doAjax('welcome.php', 'welcome', null);

    if (contentToo) {
        doAjax('content.php', 'content', null);
    }
}

function changeFav(v) {
    var elemento = document.getElementById('star');
    elemento.innerHTML = '<img src="img/loading-star.png"/>';
    
    var values = "fav=" + v;
    //alert(values);

    doAjax('star.php', 'star', values);
}

function login(email, pass) {
    var values = "email=" + email + "&password=" + pass;
    doAjax('content.php', 'content', values);
}

function cleanAll() {
    document.getElementById('footer').innerHTML = '';
    document.getElementById('star').innerHTML = '';
    document.getElementById('buttons').innerHTML = '';
    document.getElementById('answers').innerHTML = '';
    document.getElementById('organization-messages').innerHTML = '';
    document.getElementById('messages').innerHTML = '';
    document.getElementById('welcome').innerHTML = '';
}

function logoff() {    
    cleanAll();
    var values = "logoff=true";
    doAjax('content.php', 'content', values);
}

function newuser(email) {
    var values = "email=" + email;
    doAjax('newuser.php', 'content', values);
}

function createuser(email, pass1, pass2, apelido) {
    var values = "email=" + email + "&password=" + pass1
                + "&password2=" + pass2 + "&apelido=" + apelido
                + "&try=on";

    doAjax('newuser.php', 'content', values);
}

function configuracao(portugues, ingles, ordem_antigo_para_recente, ocultar_lidos, mostrar_apenas_favoritos) {
    var values = "portugues=" + portugues
               + "&ingles=" + ingles
               + "&ordem_antigo_para_recente=" + ordem_antigo_para_recente
               + "&ocultar_lidos=" + ocultar_lidos
               + "&write=checkbox";

    doAjaxComplete('organization-messages.php', 'organization-messages', values, false);
    doAjax('messages.php', 'messages', null);
}

function doConfiguracao(id) {
    if (document.getElementById(id).value == '0') {
        document.getElementById(id).value = '1';
    } else {
        document.getElementById(id).value = '0';
    }

    // corrige inconsistência
    if (id == 'portugues') {
        if (document.getElementById('portugues').value == '0'
            && document.getElementById('ingles').value == '0')
        {
            document.getElementById('ingles').value = '1';
        }
    } else if (id == 'ingles') {
        if (document.getElementById('ingles').value == '0'
            && document.getElementById('portugues').value == '0')
        {
            document.getElementById('portugues').value = '1';
        }    
    }

    configuracao(
       document.getElementById('portugues').value,
       document.getElementById('ingles').value,
       document.getElementById('ordem_antigo_para_recente').value,
       document.getElementById('ocultar_lidos').value);
}

function novaPostagem() {
    doAjax('post.php', 'posting', null);
    doAjax('messages.php', 'messages', null);
}

function goToPost(id) {
    var values = "open=" + id;
    doAjax('content.php', 'content', values);
    
    doAjax('star.php', 'star', null);
    doAjax('buttons.php', 'buttons', null);
    doAjax('answers.php', 'answers', null);
    doAjax('messages.php', 'messages', null);
}

function botaoAcao(acao) {
    var values = "acao=" + acao;    
    doAjaxComplete('buttons.php', 'buttons', values, false);

    doAjax('content.php', 'content', null);
    doAjax('star.php', 'star', null);
    doAjax('buttons.php', 'buttons', null);
    doAjax('answers.php', 'answers', null);
    doAjax('messages.php', 'messages', null);    
}