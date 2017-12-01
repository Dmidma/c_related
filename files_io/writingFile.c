/**
 *
 * writingFile.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 * This is an example of how to write to a file.
 */

#define STUDENTS 3

#include <stdio.h>

int main(void)
{
	int scores[] = { 96, 90, 83 };

	// opening a file
	FILE* file = fopen("database", "w");

	// execute code only when file is not NULL
	if (file != NULL)
	{
		for (int i = 0; i < STUDENTS; i++)
		{
			fprintf(file, "%i\n", scores[i]);
		}

		// closing the file
		fclose(file);
	}
}