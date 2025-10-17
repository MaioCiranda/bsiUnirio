document.addEventListener("DOMContentLoaded", () => {
    carregar();
    const celulas = document.querySelectorAll(".celula");
    let qualJog = 0;
    if (window.localStorage.getItem("qualJog"))
        qualJog = parseInt(window.localStorage.getItem("qualJog"));
    else
        window.localStorage.setItem("qualJog", 0);

    let vencO = 0
    if (window.localStorage.getItem("vencO"))
        vencO = parseInt(window.localStorage.getItem("vencO"));
    else
        window.localStorage.setItem("vencO", 0);

    let vencX = 0;
    if (window.localStorage.getItem("vencX"))
        vencX = parseInt(window.localStorage.getItem("vencX"));
    else
        window.localStorage.setItem("vencX", 0);

    let espacoRest = 9;
    if (window.localStorage.getItem("espacoRest"))
        espacoRest = parseInt(window.localStorage.getItem("espacoRest"));
    else
        window.localStorage.setItem("espacoRest", 9);

    let fim = false;

    sublinha(qualJog);

    document.getElementById("xis_pontos").textContent = ` ⇒ ${vencX}`
    document.getElementById("bola_pontos").textContent = `${vencX} ⇐ `

    document.getElementById("resetar").addEventListener("click", () => {
        window.localStorage.setItem("vencO", 0);
        window.localStorage.setItem("vencX", 0);
        vencO = 0;
        vencX = 0;
        document.getElementById("bola_pontos").textContent = `${vencO} ⇐ `;
        document.getElementById("xis_pontos").textContent = ` ⇒ ${vencX}`;
        reiniciarJogo();
    })

    celulas.forEach(celula => {
        celula.addEventListener("click", () => {
            if (fim || celula.innerHTML !== "") return;
            const simbolo = qualJog % 2 === 0 ? "X" : "O";
            celula.innerHTML = simbolo;
            celula.dataset.value = simbolo;
            qualJog++;
            window.localStorage.setItem("qualJog", qualJog);

            espacoRest--;
            window.localStorage.setItem("espacoRest", espacoRest);

            window.localStorage.setItem(celula.classList, celula.innerHTML)

            sublinha(qualJog);

            if (vencedor(simbolo)) {
                fim = true;
                setTimeout(() => {
                    alert(`O jogador ${simbolo} ganhou!`);
                    if (simbolo === "X") {
                        vencX++;
                        document.getElementById("xis_pontos").textContent = ` ⇒ ${vencX}`;
                        window.localStorage.setItem("vencX", vencX);
                    }
                    else {
                        vencO++;
                        document.getElementById("bola_pontos").textContent = `${vencO} ⇐ `;
                        window.localStorage.setItem("vencO", vencO);
                    }
                    reiniciarJogo();
                }, 300);
            } else if (espacoRest === 0) {
                fim = true;
                setTimeout(() => {
                    alert("Deu velha!");
                    reiniciarJogo();
                }, 300);
            }
        });
    });

    function reiniciarJogo() {
        limpar();
        celulas.forEach(c => c.innerHTML = "");
        qualJog = 0;
        window.localStorage.setItem("qualJog", 0);
        espacoRest = 9;
        window.localStorage.setItem("espacoRest", 9);
        fim = false;
        sublinha(qualJog);
    }
});

function vencedor(simbolo) {
    const possibilidades = [ ".linha1", ".linha2", ".linha3", ".coluna1", ".coluna2", ".coluna3",
        ".diagonal1", ".diagonal2"];
    for (let condicao of possibilidades) {
        const condicoes = document.querySelectorAll(condicao);
        if (Array.from(condicoes).every(c => c.innerHTML === simbolo))
            return true;
    }
    return false;
}

function sublinha (qualJog) {
    if (qualJog % 2 === 0) {
        document.getElementById("xis").style.textDecoration = "underline";
        document.getElementById("bola").style.textDecoration = "";
    }
    else {
    document.getElementById("bola").style.textDecoration = "underline";
    document.getElementById("xis").style.textDecoration = "";
    }
}

function carregar () {
    tabela = document.getElementById("tabela")
    for (let i = 0; i < 3; i++) {
        let linha = tabela.rows[i];
        for (let j = 0; j < 3; j++) {
            cell = linha.cells[j];
            classe = cell.classList;
            letra = window.localStorage.getItem(classe);
            cell.innerHTML = letra;
            cell.dataset.value = letra;
        }
    }
}

function limpar () {
    tabela = document.getElementById("tabela")
    for (let i = 0; i < 3; i++) {
        let linha = tabela.rows[i];
        for (let j = 0; j < 3; j++) {
            cell = linha.cells[j];
            classe = cell.classList;
            window.localStorage.setItem(classe, "");
        }
    }
}