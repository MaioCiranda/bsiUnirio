#include <stdio.h>

int main()
{
    int a = 0; int b = 0; int c = 0; int v;
    int m = 0; int n = 0; int t = 0;
    int am = 0; int an = 0; int at = 0; int bm = 0; int bn = 0; int bt = 0; int cm = 0; int cn = 0; int ct = 0;
    int maiore = 0; int maiorh = 0; int maiorc = 0;
    char last;
    
    // Requisitar e validar o número de respostas
    do
    {
        printf("N: ");
        scanf("%i", &v);
    }
    while (v <= 0);
    
    for (int i = 0; i < v * 2; i++)
    {
        char elev; char hor;

        // Requisitar e validar input do elevador
        if (i % 2 == 0)
        {            
            do
            {
                printf("Elevador: ");
                scanf(" %c", &elev);
            }
            while (elev != 'a' && elev != 'b' && elev != 'c' && elev != 'A' && elev != 'B' && elev != 'C');
            
            // Atualizar contadores
            switch (elev)
            {
                case 'a': case 'A': a++; last = 'a'; if (a > maiore) maiore = a; break;
                case 'b': case 'B': b++; last = 'b'; if (b > maiore) maiore = b; break;
                case 'c': case 'C': c++; last = 'c'; if (c > maiore) maiore = c; break;
            }
        }
        else
        {
            // Requisitar e validar input do horário
            do
            {
                printf("Horário: ");
                scanf(" %c", &hor);
            }
            while (hor != 'm' && hor != 'M' && hor != 'n' && hor != 'N' && hor != 't'&& hor != 'T');
            
            // Atualizar contadores
            switch (hor)
            {
                case 'm': case 'M':
                {
                    m++ ; if (m > maiorh) maiorh = m;
                    switch (last)
                    {
                        case 'a': am++; if (am > maiorc) maiorc = am; break;
                        case 'b': bm++; if (bm > maiorc) maiorc = bm; break;
                        case 'c': cm++; if (cm > maiorc) maiorc = cm; break;
                    }
                    break;
                }

                case 'n':
                {    
                    case 'N': n += 1; if (n > maiorh) maiorh = n;
                    switch (last)
                    {
                        case 'a': an++; if (an > maiorc) maiorc = an; break;
                        case 'b': bn++; if (bn > maiorc) maiorc = bn; break;
                        case 'c': cn++; if (cn > maiorc) maiorc = cn; break;
                    }
                    break;
                }

                case 't': case 'T':
                {    
                    t ++; if (t > maiorh) maiorh = t;
                    switch (last)
                    {
                        case 'a': at++; if (at > maiorc) maiorc = at; break;
                        case 'b': bt++; if (bt > maiorc) maiorc = bt; break;
                        case 'c': ct++; if (ct > maiorc) maiorc = ct; break;
                    }
                    break;
                }
            }
        }
    }
    // Printar os resultados
    printf("a)");
    if (a == maiore)
        printf(" A - %i", a);
    if (b == maiore)
        printf(" B - %i", b);
    if (c == maiore)
        printf(" C - %i", c);

    printf("\nb)");
    if (m == maiorh)
        printf(" M - %i", m);
    if (n == maiorh)
        printf(" N - %i", n);
    if (t == maiorh)
        printf(" T - %i", t);

    printf("\nc)");
    if (am == maiorc)
        printf(" A/M - %i", am);
    if (an == maiorc)
        printf(" A/N - %i", an);
    if (at == maiorc)
        printf(" A/T - %i", at);
    if (bm == maiorc)
        printf(" B/M - %i", bm);
    if (bn == maiorc)
        printf(" B/N - %i", bn);
    if (bt == maiorc)
        printf(" B/T - %i", bt);
    if (cm == maiorc)
        printf(" C/M - %i", cm);
    if (cn == maiorc)
        printf(" C/N - %i", cn);
    if (ct == maiorc)
        printf(" C/T - %i", ct);
    printf("\n");
    return 0;
}