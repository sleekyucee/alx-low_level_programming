#include "main.h"
#include <stdlib.h>

/**
 * binary_to_unit - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Description: converts binary number
 * Return: the converted number, or 0 if there is one or
 * more chars in the string b, that is not 0 or 1, or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		result <<= 1;
		result += (*b - '0');
		b++;
	}

	return (result);
}
