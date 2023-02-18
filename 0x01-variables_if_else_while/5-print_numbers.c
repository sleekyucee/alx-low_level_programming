#include <stdio.h>
/**
* main - This describes the entry point of C programs
* @void: This function does not take parameters
* Description: This program prints all single digit numbers of base 10
* starting from 0, followed by a new line.
* Return: Always 0 (success)
*/
int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
		printf("%d", a);
	putchar('\n');
	return (0);
}
