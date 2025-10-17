
#include <stdio.h>

int main()
{
    int n;
    printf("N: ");
    scanf(" %i", &n);
    int sequencia[n];
    for (int i = 0;  i < n; i++)
    {
        printf("N%i: ", i + 1);
        scanf(" %i", &sequencia[i]);
    }
    
    int ntrocas = 1;
    while (ntrocas != 0)
    {
        ntrocas = 0;
        for (int i = 0;  i <= n - 1; i++)
        {
            if (sequencia[i] > sequencia[i + 1])
            {
                int temp = sequencia[i];
                sequencia[i] = sequencia[i + 1];
                sequencia[i + 1] = temp;
                ntrocas += 1;
            }
        }
    }
    for (int i = 0;  i < n; i++)
    {
        printf(" %i", sequencia[i]);
    }
    return 0;
}