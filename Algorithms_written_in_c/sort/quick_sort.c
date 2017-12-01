/**
 *
 * quick_sort.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the quick sort.
 *
 * Best case: Ω(n log n)
 * Worst case: O(n long n)
 */

#include <stdio.h>

// prototypes of quickSort and part
void quickSort(int array[], int begIndex, int lasIndex);
int part(int array[], int begIndex, int lasIndex);


int main(void)
{
	int example[] = {15, 3, 6, 0, 0, 5, 9, 8, 5, 0, 3, 3, 5, 1, 7};

	printf("The non-sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);
	}	
   	printf("\n");

	quickSort(example, 0, 14);

	printf("The sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);			
	}
	printf("\n");
}


/**
 * This function sorts a given array using quick sort algorithm.
 * Recursively, we repeat the function on right sub-arrays of pivots
 * and left sub-arrays of pivots.
 */
void quickSort(int array[], int begIndex, int lasIndex)
{
	if (begIndex <= lasIndex)
	{
		int pivot = part(array, begIndex, lasIndex);
		quickSort(array, begIndex, pivot - 1);
		quickSort(array, pivot + 1, lasIndex);
	}
}

/**
 * This function take a pivot in an array, place it at the middle
 * after placing every lower element at its right side and every
 * bigger element at its left side.
 * Then, it returns the index of the pivot.
 */
int part(int array[], int begIndex, int lasIndex)
{
	// taking the first element as a pivot
	int pivot = array[begIndex];

	int lowpivot = begIndex + 1, highPivot = lasIndex;

	// putting every lower element at the right side
	// every bigger element at the left side
	// and the pivot at the middle
	while(lowpivot <= highPivot)
	{	
		// finding an element bigger than the pivot
		while (array[lowpivot] <= pivot && lowpivot <= lasIndex)
			lowpivot++;

		// finding an element lower than the pivot
		while (array[highPivot] > pivot)
			highPivot--;

		// swapping the lower with the bigger element
		if (lowpivot < highPivot)
		{
			int temp = array[lowpivot];
			array[lowpivot] = array[highPivot];
			array[highPivot] = temp;
		}
	}
    
	// swapping the pivot to the middle 
	int temp = array[begIndex];
	array[begIndex] = array[highPivot];
	array[highPivot] = temp;
    
    // return the index of the pivot
	return highPivot;
}
