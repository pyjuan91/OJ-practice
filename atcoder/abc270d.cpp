#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int a[105];
int main(void)
{
    int n, k, cur, turn = 1;
    long long res = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    cur = k - 1;
    while (n > 0) {
        while (n < a[cur]) {
            cur--;
        }

        if (turn == 1) {
            res += (long long)a[cur];
        }

        turn = 1 - turn;
        n -= a[cur];
    }
    printf("%lld\n", res);
    return 0;
}