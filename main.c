#include <stdio.h>

/*
 * Fejlesszen olyan alkalmazást, amely a felhasználó által megadott A és B egészérték közötti tartományban megkeresi (és összeszámolja)
 * összes az C-vel megadott egészértékkel maradék nélkül osztható számokat, majd az eredményt megjelenít a képernyőn.
 * */


int main()
{
    int a,b,c;
    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    printf("c = ");
    scanf("%d", &c);

    for (int i=c+(a%c); i<=b; i+=c)
    {
        if (i % c == 0) printf("%d ", i);
    }
    return 0;
}
