#include <stdio.h>
/**
* main - This decribes the entry point of C programs
* @void: This function does not take parameters
* Description: This program prints all single digit numbers of base 10
* starting from 0, followed by a new line. Do not use any variable of
* type char. You are to only use the putchar function not more than twice.
* Return: Always 0 (success)
*/
int main(void)
{
	int num = 48;

	while (num < 58)
	{
		putchar(num);
		num++;
	}
	putchar('\n');
	return (0);
}
