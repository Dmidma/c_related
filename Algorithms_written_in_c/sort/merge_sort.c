/**
 *
 * merge_sort.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the merge sort.
 *
 * Best case: Ω(n log n)
 * Worst case: O(n long n)
 * price: needs more space.
 */

#include <stdio.h>
#include <stdlib.h>

// prototypes of mergeSort and merge
void mergeSort(int array[], int arrayLength);
void merge(int fA[], int fSA[], int fSAL, int sSA[], int sSAL);


int main(void)
{
	int example[] = {15, 3, 6, 0, 0, 5, 9, 8, 5, 0, 3, 3, 5, 1, 7};

	printf("The non-sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);
	}	
   	printf("\n");

	mergeSort(example, 15);

	printf("The sorted array:\n");
	for (int i = 0; i < 15; i++)
	{
		printf("%d|", example[i]);			
	}
	printf("\n");
}


/**
 * This function sorts a given array using merge algorithm.
 */
void mergeSort(int array[], int arrayLength)
{
	if (arrayLength >= 2)
	{
		int middle = (arrayLength / 2);
		int length = arrayLength - middle;

		int* fSA = malloc(sizeof(int) * middle);
		int* sSA = malloc(sizeof(int) * length);

		for (int i = 0; i < middle; i++)
		{
			fSA[i] = array[i];
		}

		for (int i = middle; i < arrayLength; i++)
		{
			sSA[i - middle] = array[i];
		}		

		mergeSort(fSA, middle);
		mergeSort(sSA, length);
		merge(array, fSA, middle, sSA, length);
		free(fSA);
		free(sSA);
	}
}

/**
 * This function merge two sub-arrays (fSA and sSA) into a final array (fA).
 * the two sub-arrays must be sorted so we can have a final sorted array
 * at the end of the function.
 */
void merge(int fA[], int fSA[], int fSAL, int sSA[], int sSAL)
{
	
	// fSAI is the index for the first sub-array
	// sSAI is the index for the second sub-array
	// fAI is the index for the final array
	int fSAI = 0, sSAI = 0, fAI = 0;

	// comparing elements in the two subs and merging them in final array
	while (fSAI < fSAL && sSAI < sSAL)
	{
		if (fSA[fSAI] < sSA[sSAI])
		{
			fA[fAI] = fSA[fSAI];
			fSAI++;
		}
		else
		{
			fA[fAI] = sSA[sSAI];
			sSAI++;
		}

		fAI++;
	}

	// filling remaining elements from first sub-array into final array
	while (fSAI < fSAL)
	{
		fA[fAI] = fSA[fSAI];
		fSAI++;
		fAI++;
	}

	// filling remaining elements from the second sub-array into final array
	while (sSAI < sSAL)
	{
		fA[fAI] = sSA[sSAI];
		sSAI++;
		fAI++;
	}
}
