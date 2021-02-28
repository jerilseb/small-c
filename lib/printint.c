#include <stdio.h>
void printint(long x)
{
    printf("%ld\n", x);
}

void printchar(long x)
{
    putc((char)(x & 0x7f), stdout);
}

extern int param2(int a, int b);
extern int param8(int a, int b, int c, int d, int e, int f, int g, int h);

int main()
{
    param8(1, 2, 3, 4, 5, 6, 7, 8);
    puts("--");
    param2(1, 2);
    puts("--");
    return (0);
}
