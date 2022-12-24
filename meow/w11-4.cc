#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    map<int, int> compress;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        b[i] += 1;
        compress[a[i]] = 0;
        compress[b[i]] = 0;
    }

    int cords = 0;
    for (auto& i : compress) {
        i.second = cords++;
    }

    // cout << endl;
    // for (auto i : compress) {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    vector<vector<pair<int, int>>> projects(cords);
    for (int i = 0; i < n; i++) {
        projects[compress[b[i]]].emplace_back(
            make_pair(compress[a[i]], p[i]));
    }

    // int cnt = 0;
    // cout << endl;
    // for (auto i : projects) {
    //     cout << "cnt: " << cnt++ << endl;
    //     for (auto j : i) {
    //         cout << j.first << " " << j.second << endl;
    //     }
    // }
    // cout << endl;

    vector<long long> dp(cords, 0);
    for (int i = 0; i < cords; i++) {
        if (i > 0) {
            dp[i] = dp[i - 1];
        }
        for (auto p : projects[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[cords - 1] << endl;
    return 0;
}