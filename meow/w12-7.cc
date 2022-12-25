#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

const int mod = 1000000007;
int N, h[200200], a[200200];
long long B[200200];

long long out(int x)
{
    long long r = 0;
    while (x) {
        r = max(r, B[x]);
        x -= x & (-x);
    }
    return r;
}

void in(int x, long long p)
{
    while (x <= N) {
        B[x] = max(B[x], p);
        x += x & (-x);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) {
        long long u = out(h[i]) + a[i];
        in(h[i], u);
    }
    printf("%lld\n", out(N));

    return 0;
}