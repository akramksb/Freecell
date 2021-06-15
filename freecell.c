#include <stdio.h>
#include <stdlib.h>
#include "freecell.h"

int main()
{
    // PileCard *pileCard = createPile("testPile");
    // empiler(pileCard, createCard(1, "Tr"));
    // empiler(pileCard, createCard(12, "Pi"));
    // empiler(pileCard, createCard(4, "Co"));

    // showPile(*pileCard);

    Zone *zone = createZone1();
    
    empiler(&zone->cols[3], createCard(4, "Co"));
    empiler(&zone->cols[3], createCard(12, "Co"));
    empiler(&zone->cols[2], createCard(1, "Pi"));
    empiler(&zone->cols[1], createCard(11, "Ca"));
    showZone(*zone);
    return 0;
}