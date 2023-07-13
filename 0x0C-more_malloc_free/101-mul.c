#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: starting point (included)
 * @max: ending point (included)
 *
 * Return: pointer to the array
 */
int *array_range(int min, int max)
{
	int *range;
	int size, i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	range = malloc(sizeof(int) * size);
	if (range == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		range[i] = min;
		min++;
	}

	return (range);
}
