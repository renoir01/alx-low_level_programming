#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_rev - reverses the order of a string
 * @s: string to be reversed
 *
 * Return: always 0;
 */

void print_rev(char *s)
{
	int len;
	int i;

	len = strlen(s);
	i = len;

	while (i > 0)
	{
		i--;

		putchar(*(s + i));
	}
	putchar('\n');
}

