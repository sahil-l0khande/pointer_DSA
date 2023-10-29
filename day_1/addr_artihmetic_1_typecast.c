#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int main(void){
    char* ptr_to_char = 0;
    short* ptr_to_short = 0;
    int* ptr_to_int = 0;
    long long* ptr_to_long_long = 0;
    double* ptr_to_double = 0;
    struct Date* ptr_to_Date = 0;

    puts("printing sizes of different types and results of adding 1 into pointers:");

    printf("sizeof(char) = %zu\n",sizeof(char));
    printf("ptr_to_char + 1 = %llu\n",(unsigned long long )(ptr_to_char + 1));

    printf("sizeof(short) = %zu\n",sizeof(short));
    printf("ptr_to_short + 1 = %llu\n",(unsigned long long )(ptr_to_short + 1));

    printf("sizeof(int) = %zu\n",sizeof(int));
    printf("ptr_to_int + 1 = %llu\n",(unsigned long long )(ptr_to_int + 1));

    printf("sizeof(long long) = %zu\n",sizeof(long long));
    printf("ptr_to_long_long + 1 = %llu\n",(unsigned long long )(ptr_to_long_long + 1));

    printf("sizeof(double) = %zu\n",sizeof(double));
    printf("ptr_to_double + 1 = %llu\n",(unsigned long long )(ptr_to_double + 1));

    printf("sizeof(struct date) = %zu\n",sizeof(struct Date));
    printf("ptr_to_Date + 1 = %llu\n",(unsigned long long )(ptr_to_Date + 1));

    puts("------------------------");

    return 0;
}