#include "main.h"
#include <string.h>

/**
 * _strncat- function that concatenates strings and accepts pointer
 *
 * @dest: pointer to desticantion char
 * @src: pointer to souce char
 * @n: number of bytes to recieve
 * Return: Returns dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int lenght = strlen(dest);

	int i = 0;

	while (i < n)
	{
		dest[lenght] = src[i];
		i++;
		lenght++;
	}
	return (dest);
}
