#include <stdio.h>
/**
* main - This describes the entry point of C programs
* @void: The function does not take parameters
* Description: This program prints the alphabet in lowercase, and
* then in uppercase, followed by a new line. You are to use only the
* putchar function not more than twice.
* Return: Always 0 (success)
*/
int main(void)
{
	char sub_alpha = 'a';
	char sup_alpha = 'A';

	while (sub_alpha <= 'z')
	{
		putchar(sub_alpha);
		sub_alpha++;
	}
	while (sup_alpha <= 'Z')
	{
		putchar(sup_alpha);
		sup_alpha++;
	}
	putchar('\n');
	return (0);
}
