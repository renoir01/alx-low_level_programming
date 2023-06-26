#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Aways 0.
 */

int main(void)
{
	int n;

	n = 402;
	printf("n=%d\n", n);
	reser_to_98(&n);
	printf("n=%d\n", n);
	return (0);
}
