int sum(int a, int b);

int main()
{
    int x;
    int y;

    x = 22;
    y = sum(x, 33);

    printint(y);

    return (0);
}

int sum(int a, int b) {
    return (a+b);
}
