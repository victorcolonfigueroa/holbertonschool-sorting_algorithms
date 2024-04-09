#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer to be swapped.
 *
 * @b: Pointer to the second integer to be swapped.
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Orders a subarray around a pivot using Lomuto scheme.
 *
 * @array: The array to sort.
 *
 * @low: The starting index of the subarray to sort.
 *
 * @high: The ending index of the subarray to sort.
 *
 * @size: The full size of the array.
 *
 * Return: The final pivot position.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - Recursively apply the quick sort.
 *
 * @array: The array to sort.
 *
 * @low: The starting index of the subarray to sort.
 *
 * @high: The ending index of the subarray to sort.
 *
 * @size: The full size of the array.
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: The array to be sorted.
 *
 * @size: Number of elements in @array.
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
