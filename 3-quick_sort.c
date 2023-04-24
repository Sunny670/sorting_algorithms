#include "sort.h"

int partition(int *array, size_t size, int left, int right);
void recursive_lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * partition - Order a subset of an array of integers according to
 *                    the partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, left_id, right_id;

	pivot = array + right;
	for (left_id = right_id = left; right_id < right; right_id++)
	{
		if (array[right_id] < *pivot)
		{
			if (left_id < right_id)
			{
				swap_values(array + right_id, array + left_id);
				print_array(array, size);
			}
			left_id++;
		}
	}

	if (array[left_id] > *pivot)
	{
		swap_values(array + left_id, pivot);
		print_array(array, size);
	}

	return (left_id);
}

/**
 * recursive_lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the partition scheme.
 */
void recursive_lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (right - left > 0)
	{
		partition_index = partition(array, size, left, right);
		recursive_lomuto_sort(array, size, left, partition_index - 1);
		recursive_lomuto_sort(array, size, partition_index + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_lomuto_sort(array, size, 0, size - 1);
}