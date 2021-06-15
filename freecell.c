#include <stdio.h>
#include <stdlib.h>
#include "freecell.h"

int main()
{
    PileCard *pileCard = createPile("testPile");
    empiler(pileCard, createCard(1, "Tr"));
    empiler(pileCard, createCard(12, "Pi"));
    empiler(pileCard, createCard(4, "Co"));

    showPile(*pileCard);
    return 0;
}