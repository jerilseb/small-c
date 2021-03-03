int printf(char *fmt);

union fred
{
    char w;
    int x;
    int y;
};

union fred var1;

int main()
{
    var1.x = 65;
    printf("%d\n", var1.x);
    var1.x = 66;
    printf("%d\n", var1.x);
    printf("%d\n", var1.y);

    return (0);
}
