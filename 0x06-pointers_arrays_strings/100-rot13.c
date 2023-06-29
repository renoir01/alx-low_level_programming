#include "main.h"

/**
 * rot13 - Function that encodes a string into rot13
 * @s: Arguments pointer variable to enclode string
 * Return: Returns pointer address of s
 */

char *rot13(char *s)
{
	int i;

	int j;

	char data[] = "kfdfkfdsKdfkdDJFDjdfjfdfjfdkdKfdkOP";

	char datarot[] = "nofdslfdfjhgikKHDFJKFkdfakfdafakKfsfK";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[j] == data[j])
			{
				s[i] = datarot[j];
				break;
			}
		}
	}
	return (s);
}
