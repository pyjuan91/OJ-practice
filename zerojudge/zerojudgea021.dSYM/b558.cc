#include <cstdio>
int a[505];
int main(void)
{
    int n;
    a[0] = 1;
    for (int i = 1; i < 505; i++)
        a[i] = a[i - 1] + i;
    while (scanf("%d", &n) == 1)
        printf("%d\n", a[n - 1]);
    return 0;
}