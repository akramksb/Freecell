#ifndef _FREECELL_
#define _FREECELL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


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
Card *depiler(PileCard *pile);
void showPile(PileCard pile);

//Zone functions
Zone *createZone(int numOfCols);
Zone *createZone1();
Zone *createZone2();
Zone *createZone3();
void showZone(Zone zone);
void initZone1(Zone zone1);

//Move
void move(PileCard *depart, PileCard *arrive);
PileCard *inputToPile(char * text, Zone* z1, Zone* z2, Zone* z3);
void inputMove(Zone* z1, Zone* z2, Zone* z3);


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
    if (card->type[0] == 'C')
        printf("\033[1;31m");
    switch (card->num)
    {
    case 1:
        printf("%s  A", card->type); 
        break;
    case 11:
        printf("%s  J", card->type);
        break;
    case 12:
        printf("%s  Q", card->type);
        break;
    case 13:
        printf("%s  K", card->type);
        break;
    default:
        if (card->num<10) printf("%s  %d", card->type, card->num);
        else    printf("%s %d", card->type, card->num);
    }
    printf("\033[0m"); 
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

Card *depiler(PileCard *pile)
{
    Card *Card = pile->head->card;
    ElementPileCard *tmp = pile->head;
    pile->head = pile->head->next;
    free(tmp);
    return Card;
}

void showPile(PileCard pile)
{
    ElementPileCard *head = pile.head;
    printf("%s  :  ", pile.name);
    while ( head != NULL)
    {
        showCard(head->card);
        if (head->next)
            printf(" | ");
        head = head->next;
    }
    printf("\n");
}

//Zone functions
Zone *createZone(int numOfCols)
{
    Zone * zone = (Zone *)malloc(sizeof(Zone));
    zone->numOfCols = numOfCols;
    zone->cols = (PileCard *)malloc(sizeof(PileCard) * numOfCols);
    int i;
    for (i = 0 ; i < numOfCols ; i++)
    {
        zone->cols[i].head = NULL;
        zone->cols[i].name = "-";
    }
    return zone;
}

Zone *createZone1()
{
    Zone * zone = (Zone *)malloc(sizeof(Zone));
    zone->numOfCols = 8;
    zone->cols = (PileCard *)malloc(sizeof(PileCard) * 8);
    char* names[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
    int i;
    for (i = 0 ; i < 8 ; i++)
    {
        zone->cols[i].head = NULL;
        zone->cols[i].name = names[i];
    }
    return zone;
}

Zone *createZone2()
{
    Zone * zone = (Zone *)malloc(sizeof(Zone));
    zone->numOfCols = 4;
    zone->cols = (PileCard *)malloc(sizeof(PileCard) * 4);
    char* names[] = {"A", "B", "C", "D"};
    int i;
    for (i = 0 ; i < 4 ; i++)
    {
        zone->cols[i].head = NULL;
        zone->cols[i].name = names[i];
    }
    return zone;
}

Zone *createZone3()
{
    Zone * zone = (Zone *)malloc(sizeof(Zone));
    zone->numOfCols = 4;
    zone->cols = (PileCard *)malloc(sizeof(PileCard) * 4);
    char* names[] = {"Ca", "Pi", "Co", "Tr"};
    int i;
    for (i = 0 ; i < 4 ; i++)
    {
        zone->cols[i].head = NULL;
        zone->cols[i].name = names[i];
    }
    return zone;
}

void showZone(Zone zone)
{
    int i;
    for (i = 0; i < zone.numOfCols; i++)
    {
        showPile(zone.cols[i]);
    }
}

void initZone1(Zone zone1)
{
    srand(time(NULL));
    //create linked list of all card
    char *Types[] = {"Ca", "Co", "Pi", "Tr"};
    int i, j , numOfCard = 4*13;
    PileCard *cardList = createPile("list");
    for (i=0 ; i<4 ; i++ )
    {
        for ( j=1 ; j<=13 ; j++)
        {
            Card *card = createCard(j, Types[i]);
            empiler(cardList, card);
        }
    }

    //select card at a time and put it in zone1
    ElementPileCard *cardElPt = NULL;
    ElementPileCard *previous = NULL;
    
    for ( i =0; i<4*13; i++)
    {
        cardElPt = cardList->head;
        j = rand()%numOfCard;
        if (j == 0)
        {
            cardList->head = cardList->head->next;
        }
        else
        {
            while (j>0)
            {
                if (j == 1)
                {
                    previous = cardElPt;
                }
                cardElPt = cardElPt->next;
                j --;
            }
            previous->next = cardElPt->next;
        }
        numOfCard--;

        empiler(&zone1.cols[i%8], cardElPt->card);
        free(cardElPt);
    }

}


//Move
void move(PileCard *depart, PileCard *arrive)
{
    if (depart->head == NULL)
    {
        printf("Erreur: depart est vide\n");
        return;
    }
    Card *card = depiler(depart);
    empiler(arrive, card);
}

PileCard *inputToPile(char * text, Zone* z1, Zone* z2, Zone* z3)
{
    int i = text[0]-'1';
    if (i >= 0 && i < 8)
    {
        return &z1->cols[i];
    }
    i = text[0]-'A';
    if (strlen(text)==1 && i>=0 && i<4)
    {
        return &z2->cols[i];
    }
    if (!strcmp(text, "Ca"))    return &z3->cols[0];
    if (!strcmp(text, "Pi"))    return &z3->cols[1];
    if (!strcmp(text, "Co"))    return &z3->cols[2];
    if (!strcmp(text, "Tr"))    return &z3->cols[3];

    return NULL;
}

void inputMove(Zone* z1, Zone* z2, Zone* z3)
{
    char text[2];
    PileCard *depart, *arrive;

    printf("Depart : ");
    scanf("%s", text);
    depart = inputToPile(text, z1, z2, z3);

    printf("Arrivee : ");
    scanf("%s", text);
    arrive = inputToPile(text, z1, z2, z3);

    if ( !depart )
    {
        printf("Erreur : invalide depart col\n");
        return;
    }
    if ( !arrive )
    {
        printf("Erreur : invalide arrivee col\n");
        return;
    }
    
    
    move(depart, arrive);
}


#endif