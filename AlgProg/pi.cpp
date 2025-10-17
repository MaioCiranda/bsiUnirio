#include <stdio.h>

int main()
{
    int n; double pi; const double RAIZ_DOZE = 3.4641016151377; long denom_a = 1; int denom_b = 1;
    
    // Requisitar ao usuário um valor de n maior que 0
    do
    {
        printf("N: ");
        scanf("%i", &n);
    }
    while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        // Atualizar os valores do denominador a cada iteração a partir da segunda
        if (i != 0)
        {    
            denom_a *= 3;
            denom_b += 2;
        }
        
        // Definir o valor a ser adicionado e subraído alternadamente à pi
        double temp = (1.0 / (denom_a * denom_b));
        
        if (i % 2 == 0)
            pi += temp;
        else
            pi -= temp;
    }
    // Multiplicar pi pela raiz quadrada de doze
    pi *= RAIZ_DOZE;
    printf("%1.13lf\n",  pi);
    return 0;
}