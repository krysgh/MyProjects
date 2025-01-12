function entrar(event) {
    event.preventDefault(); 

    let email_telefone = document.getElementById("email_telefone").value;
    let senha = document.getElementById("senha").value;

    if (email_telefone === "anna@hotmail.com" && senha === "12345") {
        
    location.href='profiles.html';

    } else {


    }
}


function home() { 

    location.href='home.html';

    
}

window.addEventListener("scroll", () => {
    const header = document.getElementById("header");

    if (window.scrollY > 1) {
        header.classList.add("scrolled");
    } else {
        header.classList.remove("scrolled");
    }
});

