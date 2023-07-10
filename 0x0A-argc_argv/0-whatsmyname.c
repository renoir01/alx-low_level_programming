#include <stdio.h>
#include "main.h"

/**
 *main - Entry point of program that prints its name
 *@argv: array of arguments
 *@argc: count of command line arguments
 *Return: int 0(success)
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
