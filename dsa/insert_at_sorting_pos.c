#include <stdio.h>
#include <stdlib.h>

void insert_at_sorting_pos(int* p_arr, int N);
void test_insert_at_sorting_pos(void);
void show(int* p_arr, int N, const char* msg);

int main(void)
{
	test_insert_at_sorting_pos();

	return 0;
}

void test_insert_at_sorting_pos(void)
{
	int a1[] = {10, 45, 30, 40, 50, 60, 70, 35};
	int N1 = (int)(sizeof(a1)/sizeof(a1[0]));

	int a2[] = {10, 20, 30, 40, 50, 60, 2};
	int N2 = (int)(sizeof(a2)/sizeof(a2[0]));

	int a3[] = {20, 2};
	int N3 = (int)(sizeof(a3)/sizeof(a3[0]));

	show(a1, N1, "a1 before insert at sorting position");
	insert_at_sorting_pos(a1, N1);
	show(a1, N1, "a1 after insert at sorting position");
	
	show(a2, N2, "a2 before insert at sorting position");
	insert_at_sorting_pos(a2, N2);
	show(a2, N2, "a2 after insert at sorting position");
	
	show(a3, N3, "a3 before insert at sorting position");
	insert_at_sorting_pos(a3, N3);
	show(a3, N3, "a3 after insert at sorting position");
}

void show(int* p_arr,int N, const char* msg)
{
	int i;

	if(msg)
		puts(msg);

	for(i=0;i<N;++i)
		printf("a[%d]:%d\n", i, p_arr[i]);
}

void insert_at_sorting_pos(int* p_arr, int N)
{
	int key;
	int i;

	key = p_arr[N-1];
	i = N - 2;

	while(i > -1 && p_arr[i] > key)
	{
		p_arr[i+1] = p_arr[i];
		i =  i - 1;
	}

	p_arr[i+1] = key;
}


