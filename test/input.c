int x;
int y;
char *str;

int main()
{
    x = 4;
    y = -x + 3;

    printint(x++);
    printint(--y);

    return (0);
}
