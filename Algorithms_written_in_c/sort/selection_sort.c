/**
 *
 * selection_sort.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the selection sort.
 *
 * Best case: Ω(n²)
 * Worst case: O(n²)
 */

#include <stdio.h>

// prototype of selectionSort
void selectionSort(char array[], char arrayLength);



int main(void)
{
	char example[] = {5, 3, 16, 0, 0, 5, 9, 8, 5, 0, 3, 3, 5, 1, 7};

	printf("The non-sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);
	}	
   	printf("\n");

	selectionSort(example, 15);

	printf("The sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);			
	}
	printf("\n");
}


/**
 * This function sorts a given array using selection sort algorithm.
 * It goes through the array, selecting the smallest elements and
 * sorting them at the beggining of array.
 */
void selectionSort(char array[], char arrayLength)
{

	// iterate over the array 
	for (int i = 0; i < (arrayLength - 1); i++)
	{
		// smallest element and its position in sorted part
		char smallest = array[i];
		char position = i;

		// look through unsorted part of array
		for (int k = i + 1; k < arrayLength; k++)
		{	
			// find the next smallest element
			if (array[k] < smallest)
			{
				smallest = array[k];
				position = k;
			}
		}

		// swapping
		char temp = array[i];
		array[i] = smallest;
		array[(int) position] = temp;
	}
}
