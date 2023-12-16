#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
if (!array || !size)
return;

for (int step = 0; step < size - 1; ++step)
{

for (int i = 0; i < size - step - 1; ++i)
{

if (array[i] > array[i + 1])
{

int temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, size);
}

}

}
}
