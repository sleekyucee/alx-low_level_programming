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
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1); /* index out of range */

	unsigned long int mask = 1ul << index;

	return ((n & mask) ? 1 : 0);
}
