#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp1(vector<int>&, int, ll, int, int, vector<vector<ll>>&);
// ll dp2(vector<int>&, int, ll, int, int, vector<vector<ll>>&);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll sum = 0LL;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += 1LL * a[i];
    }
    vector DP1 = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1e13));
    // vector DP2 = vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1e13));
    // for (int i = 0; i <= n; i++) {
    //     for (int j = i; j <= n; j++) {
    //         dp1[i][j] = (dp2[i+1][j], dp2[i][j-1])
    //     }
    // }
    cout << dp1(a, n, sum, 0, n, DP1) << "\n";

    return 0;
}
ll dp1(vector<int>& a, int n, ll sum, int left, int right,
    vector<vector<ll>>& DP1)
{
    if (DP1[left][right] != -1e13)
        return DP1[left][right];
    if (n == 1)
        return DP1[left][right] = 1LL * a[left];
    if (n == 2)
        return DP1[left][right] = 1LL * max(a[left], a[left + 1]);

    return DP1[left][right] = sum
        - min(
            dp1(a, n - 1, sum - a[right - 1], left, right - 1, DP1),
            dp1(a, n - 1, sum - a[left], left + 1, right, DP1));
}
// ll dp2(vector<int>& a, int n, ll sum, int left, int right,
//     vector<vector<ll>>& DP1)
// {
//     if (DP1[left][right] != -1e13)
//         return DP1[left][right];
//     if (n == 1)
//         return DP1[left][right] = 1LL * a[left];
//     if (n == 2)
//         return DP1[left][right] = 1LL * max(a[left], a[left + 1]);
//     return DP1[left][right] = sum
//         - min(
//             dp1(a, n - 1, sum - a[right - 1], left, right - 1, DP1),
//             dp1(a, n - 1, sum - a[left], left + 1, right, DP1));
// }