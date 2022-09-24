#include <bits/stdc++.h>
using namespace std;
int a[105], dp[10005];
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
        scanf("%d", a + i);
    dp[1] = 1;
    dp[2] = a[1] == 2 ? 2 : 1;
    for (int i = 3; i <= n; i++) {
        int ma = INT_MIN;
        for (int j = 0; j < k && a[j] <= i; j++) {
            ma = max(ma, i - dp[i - a[j]]);
        }
        dp[i] = ma;
    }
    printf("%d\n", dp[n]);
    return 0;
}