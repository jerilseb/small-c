typedef int *bar;

int x, **y;

int main()
{
    x = 0;
    while (x < 100)
    {
        if (x == 5)
        {
            x = x + 2;
            continue;
        }


        if (x == 14)
        {
            break;
        }
        x = x + 1;
    }
    return (0);
}
