function seleciona(campotexto, valor) {
    var novaString = document.getElementsByName(campotexto)[0].value;    
    var key = '[' + valor + '] ';

    if (novaString.indexOf(key) >= 0) {
        novaString = novaString.replace(key, "");
    } else {
        novaString += key;
    }
    
    document.getElementsByName(campotexto)[0].value = novaString;
}