#include "main.h"

/**
 * print_array - function that prints n element of an array
 *
 * @a: pointer to first int
 * @n: pointer to second int
 * Return: nothing
 */

void print_array(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("\n");
}
