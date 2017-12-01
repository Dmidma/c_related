/**
 *
 * insertion_sort.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the insertion sort.
 *
 * Best case: Ω(n)
 * Worst case: O(n²)
 */

#include <stdio.h>

// prototype of insertionSort
void insertionSort(char array[], char arrayLength);



int main(void)
{
	char example[] = {5, 3, 16, 0, 0, 5, 9, 8, 5, 0, 3, 3, 5, 1, 7};

	printf("The non-sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);
	}	
   	printf("\n");

	insertionSort(example, 15);

	printf("The sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);			
	}
	printf("\n");
}


/**
 * This function sorts a given array using insertion sort algorithm.
 * It goes through the array, inserting unsorted elements in a left part
 * into the sorted part, the right side.
 */
void insertionSort(char array[], char arrayLength)
{

	// iterate over the array
	for (int k = 1; k < arrayLength; k++)
	{	
		// first element in the unsorted part of array
		int temp = array[k];

		// last index of the sorted part
		int j = k - 1;

		// finding the right place to insert the element in the sorted part
		while (temp < array[j] && j >= 0)
		{
			array[j + 1] = array[j];
			j--;
		}

		// putting the element in the sorted part
		array[j + 1] = temp;
	}
}
