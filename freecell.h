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
int isSameColor(Card* c1, Card* c2);

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
int isZoneEmpty(Zone Z);

//Move
void move(PileCard *depart, PileCard *arrive);
int isValideMove(PileCard *depart, PileCard *arrive);
PileCard *inputToPile(char * text, Zone* z1, Zone* z2, Zone* z3);
void inputMove(Zone* z1, Zone* z2, Zone* z3);

//Game
void showBoard(Zone *z1, Zone *z2, Zone *z3);
int isPileBlocked(PileCard* pile, Zone z1, Zone z2, Zone z3);
int isGameBlocked(Zone z1, Zone z2, Zone z3);



#endif