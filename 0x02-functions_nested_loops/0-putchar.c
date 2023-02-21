#include "main.h"
#include <unistd.h>
/**
 * _putchar - This writes the character c to stdout
 * @c: The character to print
 *
 * Return: Always 1 (success)
 * Error: -1 is returned, and error number is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
