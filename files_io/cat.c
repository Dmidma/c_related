/**
 *
 * cat.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 * This is an example of how the command "cat" works.
 */


#include <stdio.h>

int main(int argc, char* argv[])
{
	
	// cat command must be executed atleast with one file
	if (argc < 2)
	{
		printf("Usage: cat file [file ...]\n");
		return 1;
	}


	// testing if we succeded opening every file and printing its content
	for (int i = 1; i < argc; i++)
	{
		FILE* file = fopen(argv[i], "r");
		if (file == NULL)
		{
			printf("cat: %s: No shuch file or directory\n", argv[i]);
			return 1;
		}

		for (int c = fgetc(file); c != EOF; c =fgetc(file))
		{
			putchar(c);
		}
		fclose(file);
	}

	return 0;

}
