int printf(char *fmt);

char g;

int add(int a, int b);

int main()
{
    int x;
    int y;

    x = 22;
    y = add(x, 93);

    printf("Hello world, %d\n", y);

    return (0);
}

int add(int a, int b) {
    int result;
    result = a + b;
    return (result);
}
