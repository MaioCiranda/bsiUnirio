function criarMatriz(linhas, colunas) {
    const matrix = [];
    for (let i = 0; i < linhas; i++) {
      matrix.push(Array(colunas).fill(' '));
    }
    console.log(matrix);
    return matrix;
  }

function triangulo(base, caractere) {
    //9 @ T S S
    let k = base;
    let meio = k / 2 - 0.5;
    let material = caractere;
    let matriz = criarMatriz(meio + 1, k);
    for (let i = 0; i <= meio; i++) {
        matriz[i][meio] = `${material}`
        for (let j = 0; j <= i; j++) {
            matriz[i][meio - j] = `${material}`;
            matriz[i][meio + j] = `${material}`;
        }
    }
    console.log(matriz);
    return matriz;
}

function losango(base, caractere) {
    let k = base;
    let meio = k / 2 - 0.5;
    let material = caractere;
    let matriz = criarMatriz(k, k);
    for (let i = 0; i <= meio; i++) {
        matriz[i][meio] = `<div>${material}</div>`;
        for (let j = 0; j <= i; j++) {
            matriz[i][meio - j] = `<div>${material}</div>`;
            matriz[i][meio + j] = `<div>${material}</div>`;
        }
    }
    for (let i = meio + 1; i < k; i++) {
        matriz[i][meio] = `<div>${material}</div>`;
        var espelho = base - i - 1;
        for (let j = 0; j <= espelho; j++) {
            matriz[i][meio - j] = `<div>${material}</div>`;
            matriz[i][meio + j] = `<div>${material}</div>`;
        }
    }
    return matriz;
}

function esvaziar(matriz) {
    let vazia = matriz.map(linha => [...linha]);
    for (let i = 1; i < matriz.length - 1; i++) {
        for (let j = 1; j < matriz[0].length - 1; j++) {
            if (matriz[i][j] != ' ' && matriz [i][j + 1] != ' ' && matriz [i][j - 1] != ' ')
                vazia[i][j] = ' ';
        }
    }
    return vazia;
}

function printarMatriz(matriz) {
    // 1. Create table FIRST
    const table = document.createElement('table');
    table.style.borderCollapse = 'collapse';
    table.style.fontFamily = 'monospace';
    table.style.whiteSpace = 'pre';
    
    // 2. Add rows and cells
    matriz.forEach(row => {
        const tr = document.createElement('tr');
        
        row.forEach(char => {
            const td = document.createElement('td');
            td.textContent = char;
            tr.appendChild(td);
        });
        
        table.appendChild(tr);
    });
    
    // 3. Add to page LAST
    document.body.appendChild(table);
}

let k, caracter, tipo, borda, cheio;
let ehValido = false;

while (!ehValido) {
    let input = window.prompt("Elementos (Base Caractere Tipo Borda Cheio): ");
    let elementos = input.trim().split(' ');

    k = elementos[0];
    caracter = elementos[1];
    tipo = elementos[2].toUpperCase();
    borda = elementos[3].toUpperCase();
    cheio = elementos[4].toUpperCase();
    console.log(elementos);

    ehValido = (
        k >= 5 &&           
        k % 2 == 1 &&
        (tipo == 'T' || tipo == 'L') &&
        (borda == 'S' || borda == 'N') &&
        (cheio == 'S' || cheio == 'N')
    );
}
console.log(k);
console.log(caracter);

let res;
if (tipo == 'T')
    res = triangulo(k, caracter);
console.log(res);
if (tipo == 'L')
    res = losango(k, caracter);
console.log(res);
if (cheio == 'N')
    res = esvaziar(res);

console.log(res);

printarMatriz(res);