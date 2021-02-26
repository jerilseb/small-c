int c;
int x;
int *d;


int test() {
    int value;
    value = 33;
    return (value + 3);
}

void main()
{
    x = c = 84*2;
    d = &c;
    *d = 99;
    printint(x);
}
