#ifndef _FREECELL_
#define _FREECELL_

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int num;
    char *type;
} Card;

typedef struct elementPileCard
{
    Card *card;
    struct elementPileCard *next;
} ElementPileCard;

typedef struct pileCard
{
    ElementPileCard *head;
    char* name;
} PileCard;

typedef struct zone
{
    PileCard *cols;
    int numOfCols;
} Zone;


//Card functions
Card *createCard(int num, char *type);
void showCard(Card* card);

//ElementPileCard functions
ElementPileCard *createElement(Card *card);

//PileCard functions
PileCard *createPile(char *name);
void empiler(PileCard *pile, Card* card);
void showPile(PileCard pile);




//functions implementation

//Card functions
Card *createCard(int num, char *type)
{
    Card *card = (Card *) malloc(sizeof(Card));
    card->num = num;
    card->type = type;
    return card;
}

void showCard(Card* card)
{
    switch (card->num)
    {
    case 1:
        printf("%s A", card->type); 
        return;
    case 11:
        printf("%s J", card->type);
        return;
    case 12:
        printf("%s Q", card->type);
        return;
    case 13:
        printf("%s K", card->type);
        return;
    }
    printf("%s %d", card->type, card->num);
}

//ElementPileCard functions
ElementPileCard *createElement(Card *card)
{
    ElementPileCard *element = (ElementPileCard *)malloc(sizeof(ElementPileCard));
    element->card = card;
    element->next = NULL;
    return element;
}

//PileCard functions
PileCard *createPile(char *name)
{
    PileCard *pile = (PileCard *)malloc(sizeof(PileCard));
    pile->head = NULL;
    pile->name = name;
    return pile;
}

void empiler(PileCard *pile, Card* card)
{
    ElementPileCard *element = createElement(card);
    element->next = pile->head;
    pile->head = element;
}

void showPile(PileCard pile)
{
    ElementPileCard *head = pile.head;
    printf("%s\n  ", pile.name);
    while ( head != NULL)
    {
        showCard(head->card);
        if (head->next)
            printf(" | ");

        head = head->next;
    }
    
}



#endif