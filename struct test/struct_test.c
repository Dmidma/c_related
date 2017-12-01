#include <stdio.h>
#include <stdlib.h>

typedef struct Mode Mode;
struct Mode
{
    int xLCD;
    int yLCD;
    char cLCD;

};


void main()
{
    Mode *modeC = malloc(sizeof(Mode));
    Mode *modeR = malloc(sizeof(Mode));
    Mode *modeA = malloc(sizeof(Mode));


    initMode(modeC, 0, 0, 'C');
    initMode(modeR, 15, 0, 'R');
    initMode(modeA, 15, 1, 'A');

    printf("%d, %d, %c\n", modeC->xLCD, modeC->yLCD, modeC->cLCD);
    printf("%d, %d, %c\n", modeR->xLCD, modeR->yLCD, modeR->cLCD);
    printf("%d, %d, %c\n", modeA->xLCD, modeA->yLCD, modeA->cLCD);
}

void initMode(Mode *m, int x, int y, char c)
{
    m->xLCD = x;
    m->yLCD = y;
    m->cLCD = c;
}
