#include <stdio.h>
#include <stdlib.h>

void first_handler(int);
void second_handler(int);
void (*exchange(int,void(*)(int)))(int);

int main(void){
    void (*pfn)(int);

    pfn = exchange(10, first_handler);
    if(pfn == NULL)
            puts("main:no previously registed handler ");

        pfn = exchange(20,second_handler);
        if(pfn != NULL){
            pfn(100);

        }

        pfn = exchange(30,NULL);
        if(pfn != NULL){
            pfn(200);

        }

        return (0);
}

void first_handler(int n){
    printf("first_handler:n = %d\n",n);

}

void second_handler(int m){
    printf("second handler:m = %d\n",m);

}

void (*exchange(int k, void(*pfn_new)(int)))(int){
    static void (*pfn_saved)(int) = NULL;

    void (*return_pfn)(int);

    return_pfn = pfn_saved;
    pfn_saved = pfn_new;

    return (return_pfn);
}