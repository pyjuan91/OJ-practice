// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// class num {
// public:
//     long long val, mod;
//     num()
//     {
//         val = 0, mod = 0;
//     }
//     num(long long _val, long long _mod)
//     {
//         val = _val;
//         mod = _mod;
//     }
//     bool operator<(const num& b) const
//     {
//         return val < b.val;
//     }
// };
// void solve(long long, long long, long long,
//     long long, long long, long long,long long, vector<num>&);
// bool hasSol = false;
// int ans = -1;
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
// #define int long long
//     int n, k, d, v;
//     cin >> n >> k >> d;
//     vector<num> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v;
//         a[i] = num(v, v % d);
//     }
//     sort(a.rbegin(), a.rend());

//     solve(0, 0, 0, k, d, 0, n, a);
//     cout << ans << endl;

//     // for (auto i : a) {
//     //     cout << i.val << " ";
//     // }
//     // cout << endl;
//     return 0;
// }
// void solve(int cur, int sum_mod, int chosen_num,
//     int k, int d, int sum_no_mod, int n, vector<num>& a)
// {
//     if (chosen_num == k && sum_mod == 0) {
//         hasSol = true;
//         ans = sum_no_mod;
//         return;
//     }
//     for (int i = cur; i < n; i++) {
//         if (hasSol)
//             return;
//         solve(i + 1, (sum_mod + a[i].mod) % d, chosen_num + 1,
//             k, d, sum_no_mod + a[i].val, n, a);
//     }
// }

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int long long
    int n, K, d, x;
    cin >> n >> K >> d;
    vector<int> a(n + 1);
    vector<vector<vector<int>>>
        dp(n + 1, vector<vector<int>>(K + 1, vector<int>(d, -1)));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < d; k++) {
                if (dp[i][j][k] == -1)
                    continue;
                dp[i + 1][j][k] = max(dp[i + 1][j][k],
                    dp[i][j][k]);
                // cout << "i+1: " << i + 1
                //      << " j: " << j << " k: " << k << " dp: "
                //      << dp[i + 1][k][k] << endl;
                if (j != K) {
                    dp[i + 1][j + 1][(k + a[i]) % d]
                        = max(dp[i + 1][j + 1][(k + a[i]) % d],
                            dp[i][j][k] + a[i]);
                    // cout << "i+1: " << i + 1
                    //      << " j+1: " << j + 1 << " k+a[i]: " << k + a[i] << " dp: "
                    //      << dp[i + 1][j + 1][(k + a[i]) % d] << endl;
                }
            }
        }
    }

    cout << dp[n][K][0] << endl;
    return 0;
}