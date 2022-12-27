#include <bits/stdc++.h>
int main(void)
{
    long long n;
    scanf("%lld", &n);
    while (n != 1LL) {
        printf("%lld ", n);
        if (n & 1) {
            n *= 3LL;
            n += 1LL;
        } else {
            n >>= 1;
        }
    }
    printf("%lld", n);
    return 0;
}