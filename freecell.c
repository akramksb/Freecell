#include <stdio.h>
#include <stdlib.h>
#include "freecell.h"

int main()
{
    system("cls");
    // printf("%d\n", (int)((float)rand()/RAND_MAX)*8);
    
    
    
    // PileCard *pileCard = createPile("testPile");
    // empiler(pileCard, createCard(1, "Tr"));
    // empiler(pileCard, createCard(12, "Pi"));
    // empiler(pileCard, createCard(4, "Co"));

    // showPile(*pileCard);

    
    Zone *zone1 = createZone1();
    Zone *zone2 = createZone2();
    Zone *zone3 = createZone3();

    initZone1(*zone1);

    showZone(*zone2);
    printf("\n");
    showZone(*zone3);
    printf("\n");
    showZone(*zone1);

    return 0;
}