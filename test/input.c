int x;
int y;
char *str;

int main()
{
    x = 4;
    y = x++ + 3;
    if (x + 1)
    {
        printint(x);
        printint(y);
    }

    return (0);
}
