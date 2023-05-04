#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned long int number
 * @index: index, starting from 0 of the bit you want to get
 *
 * Return: the value of the bit at index index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index > sizeof(n) * 8)
	{
		return (-1);
	}

	mask <<= index;

	if (mask & n)
		return (1);
	else
		return (0);
}
