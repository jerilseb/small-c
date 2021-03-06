#include <stdio.h>
char *y = (char *)0;

int main()
{
    int x = 65535;
    char y = (char)x;

    printf("0x%lx\n", (long)y);
    return (0);
}
