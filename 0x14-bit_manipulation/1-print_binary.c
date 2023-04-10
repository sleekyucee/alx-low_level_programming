#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int bit = sizeof(unsigned long int) * 8 - 1;
	int printed = 0;

	while (bit >= 0)
	{
		if ((n >> bit) & 1)
		{
			_putchar('1');
			printed = 1;
		}

		else if (printed)
		{
			_putchar('0');
		}

		bit--;
	}

	if (!printed)
	{
		_putchar('0');
	}
}
