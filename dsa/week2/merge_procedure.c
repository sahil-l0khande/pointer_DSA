#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
void merge(int*a, ssize_t p, ssize_t q, ssize_t r);
void test_merge(void);
void show(int* a, ssize_t N, const char* msg);

int main(void)
{
	test_merge();
	return (EXIT_SUCCESS);
}

/*
 *
 * @input-1 :  pointer to array
 * #input-2,3,4: p,q,r: valid indices into array
 * @return : None 
 *
 *
 * Preconditions : 
 * 1) 0 <= p <= q < r < N.
 * 2) a[p...q] and a[q+1...r] are sorted
 *
 * Post Condition : 
 *
 * 1) a[p...q] are sorted 
 *
 *
 * */
void merge(int*a, ssize_t p, ssize_t q, ssize_t r)
{
	int* a1 = NULL;  //pointer to subarray 1
	int* a2 = NULL;  //pointer to subarray 2

	ssize_t N1, N2;	 /* Length of subarray 1,2 */
	ssize_t i, j, k;  /* Markers into subarrays and the original array */
	ssize_t index;

	//subarray length calculation
	
	N1 = q - p + 1;
	N2 = r - q;

	//subarray mem allocation
	
	a1 = (int*)calloc(N1, sizeof(int));
	if(a1 == NULL)
	{
		fprintf(stderr, "*calloc():fatal: out of memory\n");
		exit(EXIT_FAILURE);
	}

	a2 = (int*)calloc(N2, sizeof(int));
	if(a2 == NULL)
	{
		fprintf(stderr, "*calloc():fatal;out of memory\n");
		exit(EXIT_FAILURE);
	}

	//subarray cloning
	for(index = 0; index < N1 ; ++index)
		a1[index] = a[p + index];

	for(index = 0; index < N2; ++index)
		a2[index] = a[q+1+index];

	i = 0;
	j = 0;
	k = 0;

	while(TRUE)
	{
		if(a1[i] <= a2[j])
		{
			a[p + k] = a1[i];
			++i;
			++k;
			if(i == N1)
			{
				/* Sub-array a1 has exhausted */
				while(j < N2)
				{
					a[p+k] = a2[j];
					++j;
					++k;
				}
				break;
			}
		}
		else
		{
			a[p+k] = a2[j];
			++j;
			++k;
			if(j == N2)
			{
				while(i < N1)
				{
					a[p+k] = a1[i];
					++i;
					++k;
				}
				break;
			}
		}
	}

	free(a1);
	a1 = NULL;

	free(a2);
	a2 = NULL;

}

void test_merge(void)
{
	int a1[] = {30 , 21, 10, 20, 30, 40, 50, 5, 15, 35, 55, 76, 54, 100 , 200};
	ssize_t N1 = (ssize_t)sizeof(a1)/sizeof(a1[0]);
	ssize_t p1 = 2, q1 = 6, r1 = 11;

	int a2[] = {-43, -36, 20, 10, 561, 234};
	ssize_t N2 = (ssize_t)sizeof(a2)/sizeof(a2[0]);
	ssize_t p2 = 2, q2 = 2, r2  = 3;

	show(a1, N1, "a1: Before merge");
	merge(a1, p1, q1, r1);
	show(a1, N1, "a1: after merge");
	
	show(a2, N2, "a2: Before merge");
	merge(a2, p2, q2, r2);
	show(a2, N2, "a2: after merge");

}
void show(int* a, ssize_t N, const char* msg)
{
	ssize_t i;

	if(msg)
		puts(msg);

	for(i = 0; i < N; ++i)
		printf("a[%ld]:%d\n", i, a[i]);
}
