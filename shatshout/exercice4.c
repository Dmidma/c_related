#include <stdio.h>
#include <dos.h>
#include <conio.h>

int main()
{	
	int i;
	printf("N Int    | @ gestion\n");
	for (i = 0; i < 256; i++)
	{
		printf("     %d    |   %lxh    \n", i, getvect(i));
		getch();
	}



	return 0;
}