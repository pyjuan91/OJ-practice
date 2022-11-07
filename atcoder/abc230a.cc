#include <cstdio>
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 42)
        printf("AGC%03d\n", n);
    else
        printf("AGC%03d\n", n + 1);
    return 0;
}