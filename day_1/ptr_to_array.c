#include <stdio.h>

void test(void);

int main(void){
    int a[5] = {100,200,300,400,500};
    int (*pa)[5];
    pa = &a;

    int i;
    int current_element;

    puts("Using ABNORMAL method");

    for(i = 0 ; i < 5; ++i)
    {
        current_element = (*pa)[i];
        printf("Element at index %d is %d\n",i, current_element);

    }
    puts("Using normal method");
    test();

    return (0);
}

void test(void) {
    int a[5] = {100,200,300,400,500};

    int *p = a;
    int i;
    int current_element;
    for(i = 0; i < 5; ++i)
    {
        current_element = p[i];
        printf("elements at index %d is %d\n",i, p[i]);
    }
}