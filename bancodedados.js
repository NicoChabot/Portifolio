$(function() {
    var operação = "A";
    var indice_selecionado = -1;
    var tbUsuarios = localStorage.getItem("tbUsuarios");
    tbUsuarios = JSON.parse(tbUsuarios);
    if (tbUsuarios = null)
        tbUsuarios = [];
    else
        validate();
})

function Add() {
    var user = JSON.stringify({
        email: $("#email").val(),
        usuario: $("#name").val(),
        senha: $("#password").val(),
        tipo: $("#tipo").val(),
        frequencia: $("#Freq").val(),
        idade: $("#Id").val()
    });
    tbUsuarios.push(user);
    localStorage.setItem("tbUsuarios", JSON.stringify(tbUsuarios));
    alert("Registro adicionado.");
    operação = "A";
    return true;

}
$("#cadastro").on("submite", function() {
    if (operação == "A")
        return Add();
    else
        return alert("Cadastro já efetuado, faça login.");
})

function validate() {
    var user = document.getElementById(usuario);
    if (val() == 0)
        alert(Usuario_inexistente);
    else
        var user = document.getElementById(senha);
    if (val() == 0)
        alert(Senha_incorreta)
    else
        return "#btnEntrar";
}
