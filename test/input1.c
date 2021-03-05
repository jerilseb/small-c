#include <stdio.h>

int main()
{
    int x;
    x = 0;
    while (x < 25)
    {
        if (x == 5)
        {
            x = x + 3;
            continue;
        }
        printf("%d\n", x);
        x = x + 1;
    }
    printf("Done\n");
    return (0);
}
