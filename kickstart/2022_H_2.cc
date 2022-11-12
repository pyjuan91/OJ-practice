#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int dp[100005];
void init(void)
{
    for (int i = 0; i < 100005; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    dp[1] = 1;
}
void go(void)
{
    for (int i = 1; i < 100004; i++) {
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        int c = 6;
        for (int j = 2 * (i + 1); j < 100004; j += (i + 1)) {
            dp[j] = min(dp[j], dp[i + 1] + c);
            c += 2;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, l;
    init();
    go();
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        cin >> l;
        cout << "Case #" << kase << ": " << dp[l] << "\n";
    }

    return 0;
}