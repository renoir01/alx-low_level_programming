#include "main.h"

/**
 * wildcmp - function is valid if the first is equal to ther other
 * @s1: is the fist string to compare
 * @s2: is the secont string to compare
 * Return: Always 0.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '\0')
		return (0);
	if (*s1 == '\0' && *s2 != '*')
		return (0);
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	return (0);
}
