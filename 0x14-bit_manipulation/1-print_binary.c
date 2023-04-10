#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int i, counts = 0;
	unsigned long int printed;

	for (i = 63; i >= 0; i--)
	{
		printed = n >> i;

		if (printed & 1)
		{
			_putchar('1');
			counts++;
		}
		else if (counts)
			_putchar('0');
	}
	if (!counts)
		_putchar('0');
}
