#include <stdio.h>
/**
* main - This describes the entry point of C programs
* @void: The function does not take parameters
* Description: This program prints all possible different
* combinations of three digits
* Return: 0
*/
int main(void)
{
	int firstnum, secondnum, thirdnum;

	firstnum = 48;
	while (firstnum < 58)
	{
		secondnum = 49;
		while (secondnum < 58)
		{
			thirdnum = 50;
			while (thirdnum < 58)
			{
				if (thirdnum > secondnum && secondnum > firstnum)
				{
					putchar(firstnum);
					putchar(secondnum);
					putchar(thirdnum);
					if (firstnum != 55 || secondnum != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
				thirdnum++;
			}
			secondnum++;
		}
		firstnum++;
	}
	putchar('\n');
	return (0);
}
