#include <cstdio>
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%s\n", n % 2 ? "NO" : n == 2 ? "NO"
                                         : "YES");
    return 0;
}