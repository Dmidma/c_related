#include <stdio.h>
#include <dos.h>
#include <conio.h>

#define INTR 0X1C /*The clock timer interrupt*/

void interrupt(*oldhandler) ();

int count = 0;

void interrupt handler()
{
	/*increase the global counter*/
	count++;
	/*call the old routine*/
	oldhandler();
}

int main()
{
	/*save the old interrupt vector*/
	oldhandler = getvect(INTR);
	/*Install the new interrupt handler*/
	setvect(INTR, handler);
	while (count < 20)
	{
		printf("count is %d\n", count);
	}

	setvect(INTR, oldhandler);

	return 0;
}