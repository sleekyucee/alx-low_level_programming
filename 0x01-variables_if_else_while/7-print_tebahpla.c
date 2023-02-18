#include <stdio.h>
/**
* main - This describes the entry point of C programs
* @void: This function does not take parameters
* Description: This program prints the lowercase alphabet in reverse,
* followed by a new line. You are to only use the putchar function not
* more than twice.
* Return: 0
*/
int main(void)
{
	char reverse_sub_alpha = 'z';

	while (reverse_sub_alpha >= 'a')
	{
		putchar(reverse_sub_alpha);
		reverse_sub_alpha--;
	}
	putchar('\n');
	return (0);
}
