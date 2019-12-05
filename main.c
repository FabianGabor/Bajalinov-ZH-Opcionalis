#include <stdio.h>

#include <omp.h>
#define COUNT 100000

/*
 * Fejlesszen olyan alkalmazást, amely a felhasználó által megadott A és B egészérték közötti tartományban megkeresi (és összeszámolja)
 * összes az C-vel megadott egészértékkel maradék nélkül osztható számokat, majd az eredményt megjelenít a képernyőn.
 * */

void c_tobbszorosei_opt (int a, int b, int c)
{
    for (int i=(a>c)?(a + c - a%c) : (a + c % a); i<=b; i+=c)
    {
        if (i % c == 0)
            ;//printf("%d ", i);
    }
}

void c_tobbszorosei (int a, int b, int c)
{
    for (int i=a; i<=b; i++)
    {
        if (i % c == 0)
            ;//printf("%d ", i);
    }
}

int main()
{
    int a,b,c;
    //printf("a = ");
    //scanf("%d", &a);
    a = 7;

    //printf("b = ");
    //scanf("%d", &b);
    b = 10000;

    //printf("c = ");
    //scanf("%d", &c);
    c = 91;

    double startCalc, endCalc, runTime, non_opt;

    startCalc = omp_get_wtime();
    for (int i=0; i<COUNT; i++)
        c_tobbszorosei(a,b,c);
    endCalc = omp_get_wtime();
    non_opt = runTime = endCalc - startCalc;
    printf("Non-optimized: %lf\n", runTime);

    startCalc = omp_get_wtime();
    for (int i=0; i<COUNT; i++)
        c_tobbszorosei_opt(a,b,c);
    endCalc = omp_get_wtime();
    runTime = endCalc - startCalc;
    printf("    Optimized: %lf\n", runTime);

    printf("Optimized is %3.3lfx faster.\n", non_opt/runTime);

    return 0;
}
