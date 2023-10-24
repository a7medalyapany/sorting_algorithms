#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array.
 * @a: Index of the first element.
 * @b: Index of the second element.
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: The index of the pivot element after partition.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
			print_array(array, size);
		}
	}

	swap(array, i + 1, high);
	print_array(array, size);

	return i + 1;
}

/**
 * quicksort - Implements the Quick Sort algorithm using Lomuto partition.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the array using the Quick Sort algorithm.
 * It prints the array after each swap operation.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
