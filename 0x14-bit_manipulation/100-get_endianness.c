#include "main.h"

/**
 * get_endianness - checks if a machine is little endian or big endian
 * Return: 0 for big endian, and 1 for little endian
 */
int get_endianness(void)
{
	unsigned int index = 1;
	char *c = (char *) &index;

	return (*c);
}
