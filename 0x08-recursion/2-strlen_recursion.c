#include "main.h"

/**
 * _strlen_recursion - function thta returns the lentght of a string
 * @s: is the string to count
 * Return: Always 0.
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}
