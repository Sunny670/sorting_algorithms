#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending format
 *                  with  selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints array after every swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_ptr;
	size_t current_index, i;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		min_ptr = array + current_index;
		for (i = current_index + 1; i < size; i++)
			min_ptr = (array[i] < *min_ptr) ? (array + i) : min_ptr;

		if ((array + current_index) != min_ptr)
		{
			swap_values(array + current_index, min_ptr);
			print_array(array, size);
		}
	}
}