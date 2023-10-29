#include <stdio.h>
#include <stdlib.h>

struct Date { int day, month, year;} D = {7,8,2022};

void show_byte_dump(void* p , size_t N);

int main(void)
{
    unsigned char c = 0xa0;
    short s = 0x102;
    unsigned long long int lng_n = 0x10203040a0b0c0d0;

    show_byte_dump(&c,sizeof(char));
    show_byte_dump(&s,sizeof(short));
    show_byte_dump(&lng_n,sizeof(unsigned long long int));
    show_byte_dump(&D,sizeof(struct Date));

    return (0);

}
void show_byte_dump(void *p,size_t N)
{
    int i;

    puts("Hex Byte Dump:");
    for(i = 0; i< N; ++i)
        printf("p[%d]:%hhx\n",i, *(unsigned char*)((char*) p + i));


}

