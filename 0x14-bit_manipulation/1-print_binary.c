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
	unsigned long int mask = ULONG_MAX; /* mask with all bits set to 1 */
	int len = sizeof(unsigned long int) * 8; /* number of bits in n */
	/**
	 * Shift the mask to the left until the leftmost
	 * 1 is in the correct position
	 */
	while ((mask & n) == 0 && len > 1)
	{
		mask >>= 1;
		len--;
	}

	/* Print the binary representation of n */
	while (mask)
	{
		if (n & mask)
			putchar('1');
		else
			putchar('0');
		mask >>= 1;
	}
}
