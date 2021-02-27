char x;
char *str;

char test() {
    return (x + 3);
}

int main()
{
    x = 'A';
    x = test(2);

    str = "Hello world";

    printint(x);
    return (0);
}
