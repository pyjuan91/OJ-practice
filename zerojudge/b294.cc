#include <cstdio>
int main(void)
{
    int n, x;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        res += i * x;
    }
    printf("%d", res);
    return 0;
}