#include <stdio.h>
#include <stdlib.h>
#include "freecell.h"



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

        if (isZoneEmpty(*z1) && isZoneEmpty(*z2))
        {
            printf("\033[1;32m");
            printf("\nTU AS GAGNE !\n");
            printf("\033[0m"); 
            break;
        }
        if ( isGameBlocked(*z1, *z2, *z3) )
        {
            printf("\033[1;31m");
            printf("\nPARTIE BLOCKEE !\n");
            printf("\033[0m"); 
            break;
        }

        printf("\n\n");
        inputMove(z1, z2, z3);
    }
    return 0;
}