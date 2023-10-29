#include <stdio.h>

int *p;
int n = 100;

int main()
{
	p = &n;
	printf("*p = %d\n",*p);
	*p = 500;
	printf("*p = %d\n", *p);
	return (0);
}
