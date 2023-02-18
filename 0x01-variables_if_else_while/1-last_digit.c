#include <stdlib.h>
#include <time.h>
/* more headers goes there */
#include <stdio.h>
/* betty style doc for function main goes there */
/**
  * main - This describes the entry point of C programs
  * @void: The function takes no parameters
  *
  * Description: This program assigns a random number to the variable n
  * every time it is being run and prints the last digit of the number stored
  * in the variable n followed by a new line.
  * Return: ALways 0 (success)
  */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	printf("Last digit of %d is %d ", n, n % 10);
	if ((n % 10) > 5)
		printf("and is greater than 5\n");
	if ((n % 10) == 0)
		printf("and is 0\n");
	if ((n % 10) < 6 && (n % 10) != 0)
		printf("and is less than 6 and not 0\n");
	return (0);
}
