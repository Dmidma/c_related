/**
 *
 * bubble_sort.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the bubble sort.
 *
 * Best case: Ω(n)
 * Worst case: O(n²)
 */

#include <stdio.h>

// prototype of bubbleSort
void bubbleSort(char array[], char arrayLength);



int main(void)
{
	char example[] = {5, 3, 16, 0, 0, 5, 9, 8, 5, 0, 3, 3, 5, 1, 7};

	printf("The non-sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);
	}	
   	printf("\n");

	bubbleSort(example, 15);

	printf("The sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);			
	}
	printf("\n");
}


/**
 * This function sorts a given array using bubble sort algorithm.
 * It also have an optimisation. After every cycle we decrement
 * the size of the array, because after every full iteration 
 * one more element will be sorted.
 */
void bubbleSort(char array[], char arrayLength)
{

	for (int i = 0; i < (arrayLength - 1); i++)
	{
		// optimize; check if there are no swaps
		char swaps = 0;

		
		// iterate through the array
		for (int j = 0; j < (arrayLength - 1) - i; j++)
		{
			// checking the order of adjacent elements
			if (array[j] > array[j + 1])
			{
				char temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swaps++;
			}
		}

		// no swaps are made, the array is sorted
		if (!swaps)
			break;
	}
}
