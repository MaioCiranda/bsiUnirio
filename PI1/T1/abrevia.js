function isAlpha(str) {
    let regex = /[^a-zA-ZÀ-ÿ\s]/g;
    return !regex.test(str);
  }

let input = window.prompt("Nomes (separados por barras): ");
let nomes = input.split("/");
for (let i = 0; i < nomes.length; i++) {
    if (isAlpha(nomes[i])) {
        nomes[i].trim
        let palavras = nomes[i].split(" ");
        let j = 0;
        let last;
        while (j < palavras.length) {
            if (['do', 'da', 'dos', 'das', 'de', 'e', ''].includes(palavras[j].toLowerCase()))
                palavras.splice(j, 1);
            else
                j++;
        }
        
        for (j = 0; j < palavras.length; j++) {
            if (j == 0 || j == palavras.length - 1) {
                palavras[j] = palavras[j].toLowerCase().trim();
                palavras[j] = palavras[j][0].toUpperCase() + palavras[j].slice(1);
            }
            else
            palavras[j] = palavras[j][0].trim().toUpperCase();
        }

        nomes[i] = palavras.join(" ");
    }

    else 
        nomes[i] = "-----NOME INVÁLIDO-----"
}

let html = nomes.map(nome => `<h2>${nome}</h2>`).join('')
document.getElementById('content').innerHTML = html;