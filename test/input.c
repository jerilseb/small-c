int printf(char *fmt);

void printstr(char **str) {
    printf("%s", str);
}

int main()
{
    char *s;
    s = "This is a test";
    printstr(s);

    return (0);
}
