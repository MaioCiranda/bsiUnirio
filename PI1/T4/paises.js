import { countries } from "./countries.js";
document.addEventListener("DOMContentLoaded", () => {
    let paginaAtual = 1;
    let qtdPaises = 10;
    let regiaoAtual = "";
    let pesquisaAtual = "";
    let layout = "lista";

    const paises = document.getElementById("paises");
    const regiao = document.getElementById("listaRegiao");
    const nomePais = document.getElementById("nomePais");
    const novoQtdPaises = document.getElementById("qtdPaises");
    const regiaoSelecionada = document.getElementById("listaRegiao").value;

    regiao.addEventListener("change", () => {
        regiaoAtual = regiao.value;
        paginaAtual = 1;
        render();
    });

    nomePais.addEventListener("input", () => {
        pesquisaAtual = nomePais.value.toLowerCase();
        paginaAtual = 1;
        render();
    });

    novoQtdPaises.addEventListener("input", () => {
        const val = parseInt(novoQtdPaises.value);
        if (val > 0) {
            qtdPaises = val;
            paginaAtual = 1;
            render();
        }
    });

    function filtrarPaises() {
        if (regiaoAtual == "outros")
            return countries.filter(country => 
                !["EU", "NA", "SA", "AS", "AF", "OC"].includes(country.region)
            );
        return countries.filter(pais => {
            const matchRegiao = regiaoAtual === "" || pais.region === regiaoAtual;
            const matchNome = pais.name.toLowerCase().includes(pesquisaAtual);
            return matchRegiao && matchNome;
        });
    }

    function printarPais(pais) {
        const moeda = pais.currency;
        const idioma = pais.language;
        const imgSrc = `flags/${pais.code.toLowerCase()}.png`;

        return `
            <div class="pais-${layout}">
                <div class="info">
                    <p>Nome: ${pais.name} (${pais.code})</p>
                    <p>Capital: ${pais.capital}</p>
                    <p>Região: ${pais.region}</p>
                    <p>Moeda: ${moeda.symbol || "-"} - ${moeda.name || "-"} (${moeda.code || "-"})</p>
                    <p>Idioma: ${idioma.name || "-"} (${idioma.code})</p>
                    </div>
                <div">
                    <img src="${imgSrc}" alt="Bandeira de ${pais.name}" class="bandeira-${layout}"/>
                </div>
            </div>
        `;
    }

    function render() {
        const filtrados = filtrarPaises();
        const total = filtrados.length;
        const totalPaginas = Math.ceil(total / qtdPaises);
        let inicio = (paginaAtual - 1) * qtdPaises;
        let pagina = filtrados.slice(inicio, inicio + qtdPaises);

        paises.innerHTML = `
            <p style="padding-top: 10px; padding-bottom: 10px; color:#143e93;">
            <strong>Total de países: ${total} encontrados</strong>
            <button style="margin-left: 20px; margin-right: 5px;" id="voltarPagina"><<</button>
             <strong>Página: ${paginaAtual} de ${totalPaginas}</strong>
             <button style="margin-left: 5px;" id="passarPagina">>></button></p>
            ${pagina.map(printarPais).join("")}
        `;

        document.getElementById("passarPagina").addEventListener("click", () => {
            if (paginaAtual < totalPaginas)
                paginaAtual++;
            render();
        });

        document.getElementById("voltarPagina").addEventListener("click", () => {
            if (paginaAtual > 1)
                paginaAtual--;
            render();
        });
    }

    document.getElementById("modoLista").addEventListener("click", () => {
        layout = "lista";
        render();
    });

    document.getElementById("modoBloco").addEventListener("click", () => {
        layout = "bloco";
        render();
    });

     render();
});