int sum(int *a, int b);
int printf(char *fmt);

int main()
{
    int x;
    int y;

    x = 22;
    y = sum(&x, 33);

    printf("Hello world, %d\n", y);

    return (0);
}
