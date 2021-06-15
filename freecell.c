#include <stdio.h>
#include <stdlib.h>
#include "freecell.h"

void showBoard(Zone *z1, Zone *z2, Zone *z3)
{
    showZone(*z2);
    printf("\n");
    showZone(*z3);
    printf("\n");
    showZone(*z1);
}

int main()
{

    //init
    Zone *z1 = createZone1();
    Zone *z2 = createZone2();
    Zone *z3 = createZone3();
    initZone1(*z1);
    
    //game loop
    while(1)
    {
        system("cls");

        showBoard(z1, z2, z3);

        printf("\n\n");

        inputMove(z1, z2, z3);
    }

    return 0;
}