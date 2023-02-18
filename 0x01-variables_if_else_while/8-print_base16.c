#include <stdio.h>
/**
* main - This decribes the entry point of C programs
* @void: This function does not take parameters
* Description: This program prints all the numbers of base 16 in
* lowercase, followed by a new line.
* Return: 0
*/
int main(void)
{
	char hex_num = 48;
	char hex_alpha = 'a';

	while (hex_num <= 57)
	{
		putchar(hex_num);
		hex_num++;
	}
	while (hex_alpha <= 'f')
	{
		putchar(hex_alpha);
		hex_alpha++;
	}
	putchar('\n');
	return (0);
}
