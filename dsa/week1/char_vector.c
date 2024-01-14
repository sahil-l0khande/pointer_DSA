#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define TRUE 1 

struct vector 
{
    char**p_arr; 
    ssize_t N; 
}; 

struct vector* create_vector(void); 
void push_back(struct vector* p_vector, char* new_element); 
void show_vector(struct vector* p_vector); 
void release_vector(struct vector* p_vector); 
int  find_word(struct vector* p_vector, char* search);
int main(int argc, char*argv[])
{
    struct vector* p_vector = NULL; 
    int choice, num;
    char *word, *search;
    char buffer[1024];

    if (argc < 3)
    {
	    fprintf(stderr, "fatal: invalid arguments\n");
	    exit(EXIT_FAILURE);
    }

    search = argv[2];

    FILE* fp = fopen(argv[1], "r");
    char *line;
    int cnt = 0;
    if(!fp) 
    {
	    fprintf(stderr, "Error : Opening file\n");
	    exit(EXIT_FAILURE);
    }
    p_vector = create_vector(); 
    line = buffer;
    while(fgets(line, 1024, fp))
    {

	    if(line != NULL ) {
		    //printf("line is %s\n", line);
	            buffer[strcspn(buffer, "\n")] = '\0';
		    while ((word = strsep(&line, " ")) != NULL) {
			    //printf("%s\n", word);
			    push_back(p_vector, word);
		    }

		    line = buffer;
	    }
    }

    puts("User input:"); 
    show_vector(p_vector); 

    find_word(p_vector, search);
    release_vector(p_vector); 
    p_vector = NULL; 

    fclose(fp);
    return (0); 
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

    p_vector->p_arr = NULL; 
    p_vector->N = 0; 

    return (p_vector); 
}

void push_back(struct vector* p_vector, char* new_element)
{
    p_vector->p_arr = (char**)realloc(
                                    p_vector->p_arr, 
                                    (p_vector->N + 1) * sizeof(char*)
                                ); 
    if(p_vector->p_arr == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    p_vector->N = p_vector->N + 1; 
    p_vector->p_arr[p_vector->N - 1] = strdup(new_element); 

    if (p_vector->p_arr[p_vector->N - 1] == NULL) {
	    fprintf(stderr, "strdup():fatal:out of memory\n");
	    exit(EXIT_FAILURE);
    }
}

int find_word(struct vector* p_vector, char * search)
{
	int i, cnt = 0;
	for(i = 0; i < p_vector->N; ++i)
	{
		if(!strcmp(p_vector->p_arr[i], search))
		{
			cnt++;
		}
	}
	printf("WORD APPEARS %d NUMBER OF TIMES\n", cnt);
	return 0;
}
void show_vector(struct vector* p_vector)
{
    int i; 

    for(i = 0; i < p_vector->N; ++i)
        printf("p_vector->p_arr[%d]:%s\n", i, p_vector->p_arr[i]); 
}

void release_vector(struct vector* p_vector)
{
    if(p_vector != NULL)
    {
	    int i;
	    for(i = 0; i < p_vector->N ; i++)
		    free(p_vector->p_arr[i]);
        if(p_vector->p_arr != NULL)
            free(p_vector->p_arr); 
        free(p_vector); 
    }
}
