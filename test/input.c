int sum(int a, int b);
int printf(char *fmt);

int main()
{
    int x;
    int y;

    x = 22;
    y = sum(x, 33);

    printf("Hello world, %d\n", 23);

    return (0);
}

int sum(int a, int b)
{
    return (a + b);
}
