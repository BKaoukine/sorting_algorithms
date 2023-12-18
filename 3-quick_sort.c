#include "sort.h"
/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
/* Choosing the last element as the pivot */
int pivot = array[high];
size_t i = low, j;

/* Iterate through the array */
for (j = low; j < high; j++) {
/* If the current element is smaller than or equal to the pivot */
if (array[j] <= pivot) {
/* Swap and print the array after each swap */
swap(&array[i], &array[j]);
if (i != j)
print_array(array, size);
/* Increment the index of the smaller element */
i++;
}
}

/* Swap the pivot to its correct position and print the array */
swap(&array[i], &array[high]);
if (i != high)
print_array(array, size);

/* Return the index of the pivot element */
return (i);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
/* Recursive function, continues until the low index is less than high index */
if (low < high)
{
/* Partition the array and get the pivot index */
size_t partition_index = lomuto_partition(array, low, high, size);

/* Recursively sort the subarrays before and after the pivot */
if (partition_index > 0)
quick_sort_recursive(array, low, partition_index - 1, size);

quick_sort_recursive(array, partition_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
/* Check for invalid input or already sorted array */
if (array == NULL || size < 2)
return;

/* Call the helper function to perform quicksort */
quick_sort_recursive(array, 0, size - 1, size);
}
