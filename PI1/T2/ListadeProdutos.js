document.addEventListener("DOMContentLoaded", adicionaProduto = () => {
    const form = document.forms["adiciona"];
    const addProduto = document.getElementById("add_produto");
    const listaProduto = document.getElementById("lista_produtos");
    const botoesLista = document.getElementById("botoes_lista");
    const botoesAdd = document.getElementById("botoesDeAddProduto");
    const cancelar = document.getElementById("cancelar");
    const inserir = document.getElementById("inserirItem");
    const editar = document.getElementById("editar");
    const excluir = document.getElementById("excluir");

    listaProduto.style.display = "none";
    botoesLista.style.display = "none";
    document.getElementById("descricao").focus();

        form.addEventListener("submit", (event) => {
            event.preventDefault(); 
            const descricao = document.getElementById("descricao").value.trim();
            const preco = document.getElementById("preco").value;

            if (descricao === "" || preco === "") {
                alert("Preencha todos os campos!");
                return;
            }
            else if (descricao.length < 2 || descricao.length > 60) {
                console.log(descricao.length);
                alert("Descrição inválida.");
                return;
            }
            else if (preco < 0.01 || preco > 9999.99) {
                alert("Preço inválido.");
                return;
            }
            
            addProdutoNaLista(descricao, parseFloat(preco).toFixed(2), form);

            addProduto.style.display = "none";
            listaProduto.style.display = "table";
            botoesLista.style.display = "flex";

            form.reset();
        })
    
    cancelar.addEventListener("click", () => {
        addProduto.style.display = "none";
        listaProduto.style.display = "table";
        botoesLista.style.display = "flex";
    })

    inserir.addEventListener("click", () => {
        addProduto.style.display = "flex";
        listaProduto.style.display = "none";
        botoesLista.style.display = "none";
    });


    excluirTudo.addEventListener("click", () => {
        if(confirm("Tem certeza que deseja excluir todos os produtos?")) {
            const tabela = document.getElementById("lista_produtos");
            console.log(tabela.rows.length);
            while (tabela.rows.length != 1) {
                removerProdutoDaLista(1);
            }
        }
    })

  document.addEventListener('click', (e) => {
    if (e.target.classList.contains('excluir') || e.target.classList.contains('editar')) {
        const row = e.target.closest('tr');
        const descricao = row.cells[0].textContent;
        const preco = row.cells[1].textContent;

        if (e.target.classList.contains('excluir') ) {
            if (window.confirm(`Tem certeza que deseja excluir o produto ${descricao}?`)) {
                removerProdutoDaLista(row.rowIndex);
            }
        } else if (e.target.classList.contains('editar')) {
            e.target.blur();
            addProduto.style.display = "flex";
            listaProduto.style.display = "none";
            botoesLista.style.display = "none";
            document.getElementById("descricao").value = descricao;
            document.getElementById("preco").value = preco;
            form.dataset.editandoId = row.id;
            setTimeout(() => {
                const campoDescricao = document.getElementById("descricao");
                campoDescricao.focus();
                campoDescricao.select();
            }, 0);
        }
     }   
    });
})

let contador = 0;

function addProdutoNaLista(descricao, preco, form) {
    const tabela = document.getElementById("lista_produtos");
    const linhas = tabela.getElementsByTagName("tr").length - 1;
    const novaLinha = tabela.insertRow(-1);
    const editandoId = form.dataset.editandoId;
     if (editandoId) {
        const linhaAntiga = document.getElementById(editandoId);
        if (linhaAntiga) {
            const index = linhaAntiga.rowIndex;
            removerProdutoDaLista(index);
        }
        delete form.dataset.editandoId;
    }
    novaLinha.id = `linha-${contador}`;
    contador++;

    novaLinha.className = linhas % 2 === 0 ? `par` : `impar`;
    const celulaDescricao = novaLinha.insertCell(0);
    const celulaPreco = novaLinha.insertCell(1);
    const celulaAcoes = novaLinha.insertCell(2);

    celulaDescricao.className = "descrição";
    celulaPreco.className = "preço";
    celulaAcoes.className = "botões";

    celulaDescricao.textContent = descricao;
    celulaPreco.textContent = preco;

    celulaAcoes.innerHTML = `<button type="button" class="editar">Editar</button>
                             <button type="button" class="excluir">Excluir</button>`;
}

function removerProdutoDaLista(index) {
    const tabela = document.getElementById("lista_produtos");
    tabela.deleteRow(index);
    for (let i = index; i < tabela.rows.length; i++) {
        if (tabela.rows[i].className === 'par')
            tabela.rows[i].className = 'impar';
        else
        tabela.rows[i].className = 'par';
    }
}