#include <stdio.h>

struct A
{
	int a;
	char b;
	float c;
};

struct A (*pA)[5];
struct A arr[5] = {
	{10, 'a', 3.14f},
	{20, 'b', 4.15f},
	{30, 'c', 5.16f},
	{40, 'd', 6.17f},
	{50, 'e', 7.18f}
};

int main()
{
	int i;
	int copy_a;
	int copy_b;
	float copy_c;

	pA = &arr;

	for(i = 0; i < 5; ++i)
	{
		copy_a = (*pA)[i].a;
		copy_b = (*pA)[i].b;
		copy_c = (*pA)[i].c;

		printf("index = %d\n copy_a = %d\n copy_b = %c\n copy_c = %.2f\n",
				i, copy_a , copy_b, copy_c);
		puts("------------------------------------------");
	}

	return (0);

}
