#include <stdio.h>

int main()
{
    int n; int k; int comp; int vi; int soma = 0;
    // Requisitar valores ao usuário
    do
    {
        printf("N: ");
        scanf("%i", &n);
    }
    while (n < 2);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("S%i: ", (i + 1));
        scanf("%i", &arr[i]);
    }

    do
    {
        printf("K: ");
        scanf("%i", &k);
    }
    while (k < 2 || k > n);

    // Iterar por cada sequência de k números no array
    for (int i = 0; i <= n - k; i++)
    {
        int seq = 0;
        for (int j = 0; j < k; j++)
        {
            seq += arr[i + j];
        }
        
        // Inverter as somatórias negativas para comparação
        if (seq < 0)
            seq = -seq;
        
        // guargar o primeiro elemento da menor sequência
        if (seq < comp || i == 0)
        {
            comp = seq;
            vi = i;
        }
    }
    // Atualizar e printar os valores de saída
    for (int i = 0; i < k; i++)
    {
        soma += arr[vi + i];
        printf("%i ", arr[vi + i]);
    }
    printf("\n%i\n", soma);
    return 0;
}