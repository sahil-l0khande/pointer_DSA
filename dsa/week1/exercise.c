#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector
{
	char words[256];
	ssize_t N;
};

struct vector* create_vector(void);
void release_vector(struct vector* p_vector);

int main(int argc, char*argv[])
{
	if(argc < 3) 
	{
		fprintf(stderr, "fatal: invalid arguments\n");
		exit(EXIT_FAILURE);
	}

	FILE* fp = fopen(argv[1],"r");
	struct vector* p_vector = NULL;
	char line[1024];
	int cnt = 0;
	if (!fp) 
	{
		fprintf(stderr, "Error : Opening file\n");
		exit(EXIT_FAILURE);
	}

	p_vector = create_vector();

	printf("word:%s size %ld\n", p_vector->words, p_vector->N);

	while(fgets(line, 1024, fp))
	{
		printf("word is %s\n", word);
		++cnt;
		printf("count is %d\n", cnt);

	//	push_back(p_vector, line);
		//scanf("%d", &choice);
	}

	release_vector(p_vector);
	fclose(fp);
	return 0;
}

/*
void push_back(struct vector* p_vector, char* new_element)
{
	p_vector->words = (char)realloc(
			p_vector->words,
			(p_vector->N + 1) * sizeof(char)
			);
	if(p_vector->words == NULL)
	{
		fprintf(stderr, "realloc():fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}

	p_vector->N = p_vector->N + 1;
	p_vector->words[p_vector->N -1] = new_element;
}

void show_vector(struct vector* p_vector)
{
	int i;
	for(i = 0; i < p_vector->N; ++i)
		printf("p_vector->p_arr[%d]:%d\n", i, p_vector->words[i]);
}

*/
void release_vector(struct vector* p_vector)
{
	if(p_vector != NULL)
	{
		if(p_vector->words != NULL)
			free(p_vector->words);
		free(p_vector);
	}
}
struct vector* create_vector(void)
{
	struct vector* p_vector = NULL;

	p_vector = (struct vector*)malloc(sizeof(struct vector));

	if(p_vector == NULL)
	{
		fprintf(stderr, "malloc():fatal:out of memory\n");
		exit(EXIT_FAILURE);
	}

	memset(p_vector->words, 0, 256);
	p_vector->N = 0;

	return (0);
}
