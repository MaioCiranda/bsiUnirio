#include <stdio.h>
#include <math.h>

int main()
{
    int n; float x; float y;
    
    // Requisitar os inputs do usuário
    printf("x, y: ");
    scanf("%f %f", &x, &y);
    
    do
    {
        printf("N: ");
        scanf("%i", &n);
    }
    while (n < 1);

    float arr[n * 2];
    for (int i = 0; i < n * 2; i++)
    {
        if (i % 2 == 0)
            printf("x: ");
        else
            printf("y: ");
        scanf("%f", &arr[i]);
    }

    // Inicializar todos os valores de raios[] para indicar o fim do array
    float raios[n];
    for (int i = 0; i < n; i++)
    {    
        raios[i] = -1;
    }

    // Iterar por cada dupla de x e y
    for (int i = 0; i < n * 2; i += 2)
    {
        // Calcular o raio
        float cata = pow((x - arr[i]), 2);
        float catb = pow((y - arr[i + 1]), 2);
        float hip = sqrt(cata + catb);
        
        // Adicionar o raio em raios[] caso não haja um raio igual
        for (int j = 0; j < n; j++)
            {
                if (raios[j] == hip)
                    break;
                if (raios[j] == -1)
                {
                    raios[j] = hip;
                    break;
                }
            }
    }
    // Printar os raios
    for (int i = 0; i < n; i++)
    {
        if (raios[i] == -1)
            break;
        printf("%.6f\n", raios[i]);
    }
    return 0;
   
}
