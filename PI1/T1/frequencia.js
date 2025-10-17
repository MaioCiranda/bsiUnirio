import prompt from 'prompt-sync';
const promptFunc = prompt();

// Inputs do usuário
let n = 0;
while (n < 2) {
    n = promptFunc(`Número: `);
}
let numeros = promptFunc(`Números (${n} elementos): `);
// Popula o vetor com os números
let vetor1 = new Array(Number(n)).fill('');
let contador = 0;
for (let i = 0; i < numeros.length; i++) {
    if (numeros[i] != ' ' && numeros[i] != '\n')
        vetor1[contador] = vetor1[contador] + numeros[i];
    else if (numeros[i + 1] != ' ' && numeros[i + 1] != '\n')
        contador++;
}

// Remove NaNs
let i = 0;
while (i < vetor1.length) {
    if (isNaN(vetor1[i]))
        vetor1.splice(i, 1);
    else
        i++;
}

// Cria vetor sem cópias
let semCopias = [...vetor1]; 
i = 0;
while (i < semCopias.length) {
    let j = i + 1;
    while (j < semCopias.length) {
        if (semCopias[j] == semCopias[i])
            semCopias.splice(j, 1);
        else
            j++;
    }
    i++;
}

// Computa quantidades
let qtd = semCopias.map(numero => vetor1.filter(x => x == numero).length);

// Computa maior/menor
let minmax = new Array(Number(semCopias.length)).fill('');
let maior = Math.max(...qtd);
let menor = Math.min(...qtd);
minmax[qtd.indexOf(maior)] = "+";
minmax[qtd.indexOf(menor)] = "-";

// Saída
let out = [];

for (i = 0; i < semCopias.length; i++) {
    out[i] = semCopias[i] + ": " + qtd[i] + " vez(es) " + minmax[i]
}

out = out.map(numero => `${numero}`).join('\n')
console.log(out)
