/**
 *
 * binary_search.c
 *
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This file contains an example of a usage of the binary search.
 *
 * Best case: Ω(1)
 * Worst case: O(log n)
 * Assumptions:
 *			-Sorted list
 *			-Random access
 */


#include <stdio.h>

// prototype of binarySearch
char binarySearch(char array[], char wantedValue, char arrayLength);



int main(void)
{
	char example[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};

	char result = binarySearch(example, 5, 9);
	if (result == -1)
		printf("The wanted value does not exist in this array!\n");
	else
		printf("The wanted values does exist in this array at index : %d\n", result);
}


/**
 * This function will retun the index of the wantedValue
 * if it is available in the array.
 * Else, it will return -1.
 */
char binarySearch(char array[], char wantedValue, char arrayLength)
{

	// boundaries of the searched zone
	char lower = 0;
	char upper = arrayLength - 1;

	// binary search
	while (lower <= upper)
	{
		// find the middle
		char middle = (lower + upper) / 2;

		if (array[middle] == wantedValue)
			return middle;
		else if (array[middle] < wantedValue)
			lower = middle + 1;
		else if (array[middle] > wantedValue)
			upper = middle - 1;
	}

	// wantedValue does not exist in the array
	return -1;
}
