#include <stdio.h>
#include <dos.h>
#include <conio.h>

#define INTR 0X09 /*The clock timer interrupt*/

void interrupt(*oldhandler) ();

int count = 0;

void interrupt handler()
{
	// print the message
	printf("Coucou, une interruption clavier est arrivé!!\n");

	/*call the old routine*/
	oldhandler();
}

int main()
{
	/*save the old interrupt vector*/
	oldhandler = getvect(INTR);

	/*Install the new interrupt handler*/
	setvect(INTR, handler);

	scanf("%c", NULL);


	setvect(INTR, oldhandler);

	return 0;
}