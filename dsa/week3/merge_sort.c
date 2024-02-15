#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

void  fill_array(int *p, ssize_t N);
void fill_array2(int*p, ssize_t N);
void  show_array(int* p, ssize_t N, const char* msg);
void sort(int*p, ssize_t N);
void sort2(int*p,ssize_t N);
void merge(int *a, ssize_t p, ssize_t q, ssize_t r);
void merge_sort(int *a, ssize_t p, ssize_t r);
void merge_sort2(int*a, ssize_t p, ssize_t r);
void merge2(int*a, ssize_t p, ssize_t q, ssize_t r);
int main(int argc, char* argv[])
{
	int *a = NULL;
	ssize_t N = 0;

	if(argc != 2)
	{
		fprintf(stderr, "Usage Error:%s number of elements\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	N = atoll(argv[1]);
	if(N <= 0)
	{
		fprintf(stderr, "Bad size for array");
		exit(EXIT_FAILURE);
	}

	a = (int*)calloc(N, sizeof(int));

	if(a == NULL)
	{
		fprintf(stderr, "calloc():fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}

	fill_array2(a, N);
	show_array(a, N, "Array : Before sort");
	sort2(a, N);
	show_array(a, N, "Array : After sort");

	free(a);
	a = NULL;

	return (EXIT_SUCCESS);
}

void merge(int *a, ssize_t p, ssize_t q, ssize_t r)
{
	int *a1 = NULL;
	int *a2 = NULL; 

	ssize_t N1, N2;
	ssize_t i,j,k;
	ssize_t index;

	N1 = q - p + 1;
	N2 = r - q;

	a1 = (int*)calloc(N1, sizeof(int));
	if(a1 == NULL)
	{
		fprintf(stderr, "calloc():fatal:out of memory");
		exit(EXIT_FAILURE);
	}

	a2 = (int*)calloc(N2, sizeof(int));
	if(a2 == NULL)
	{
		fprintf(stderr, "calloc():fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}

	for(index = 0; index < N1; ++index)
		a1[index] = a[p+index];

	for(index = 0; index < N2; ++index)
		a2[index] = a[q+1+index];

	j=0;
	k=0;
	i=0;

	while(TRUE)
	{
		if(a1[i] <= a2[j])
		{
			a[p+k] = a1[i];
			++i;
			++k;

			if(i == N1)
			{
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



void fill_array(int*p, ssize_t N)
{
	ssize_t i;

	srand(time(0));
	for(i = 0; i < N; ++i)
		p[i] = rand();
}

void  fill_array2(int*p, ssize_t N)
{
	ssize_t i;

	srand(time(0));
	for(i = 0; i < N; ++i)
		p[i] = rand();
}

void show_array(int* p, ssize_t N, const char* msg)
{
	ssize_t i;
	if(msg)
		puts(msg);

	for(i = 0; i < N; ++i)
		printf("p[%ld]: %d\n",i, p[i]);
}

void merge_sort(int *a, ssize_t p, ssize_t r)
{
	ssize_t q;
	if(p < r)
	{
		q = (p + r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge2(a, p, q, r);
	}
}

void merge_sort2(int*a, ssize_t p, ssize_t r)
{
	ssize_t q;
	if(p < r)
	{
		q = (p + r) / 2;
		merge_sort2(a, p, q);
		merge_sort2(a, q+1, r);
		merge2(a, p, q, r);
	}
}

void sort(int* p, ssize_t N)
{
	merge_sort(p, 0, N-1);
}

void sort2(int*p, ssize_t N)
{
	merge_sort2(p, 0, N-1);
}
void merge2(int *a, ssize_t p, ssize_t q, ssize_t r)
{
	int *a1 = NULL;
	int *a2 = NULL;

	ssize_t N1, N2;
	ssize_t i, j, k;
	ssize_t index;

	N1 = q - p + 1;
	N2 = r - q;

	a1 = (int*)calloc(N1, sizeof(int));
	if(a1 == NULL)
	{
		fprintf(stderr, "calloc():fatal:out of memory");
		exit(EXIT_FAILURE);
	}

	a2 = (int*)calloc(N2, sizeof(int));
	if(a2 == NULL)
	{
		fprintf(stderr, "calloc():fata:out of memory");
		exit(EXIT_FAILURE);
	}

	for(index = 0; index < N1; ++index)
		a1[index] = a[p + index];

	for(index = 0; index < N2; ++index)
		a2[index] = a[q + 1 + index];

	i=0;
	j=0;
	k=0;

	while(TRUE)
	{
		if(a1[i] <= a2[j])
		{
			a[p + k] = a1[i];
			++i;
			++k;

			if(i == N1)
			{
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
			a[p + k] = a2[j];
			++j;
			++k;

			if(j == N2)
			{
				while(i < N1)
				{
					a[p +k] = a1[i];
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
