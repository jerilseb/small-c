int printf(char *fmt);

enum fred
{
    apple = 1,
    banana,
    carrot,
    pear = 10,
    peach,
    mango,
    papaya
};

enum jane
{
    aple = 1,
    bnana,
    crrot,
    par = 10,
    pech,
    mago,
    paaya
};

enum fred var1;
enum jane var2;
enum fred var3;

typedef int *FOO;

struct bar
{
    int x;
    int y
};

typedef struct bar *BAR;
BAR var22;

int main()
{
    var1 = carrot + pear + mango;
    printf("%d\n", var1);

    return (0);
}
