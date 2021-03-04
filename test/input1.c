#include <stdio.h>

void run();

extern int x;

int main()
{
    run();
    printf("%d\n", x);
    return (0);
}
