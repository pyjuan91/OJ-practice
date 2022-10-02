#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end());
    vector<int> B;
    for (int i = 0; i < n; i++) {
        B.emplace_back(v[i].second);
    }

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        vector<int>::iterator iter;
        iter = lower_bound(dp.begin(), dp.end(), B[i]);

        if (iter == dp.end()) {
            dp.emplace_back(B[i]);
        } else {
            *iter = B[i];
        }
    }

    cout << n + dp.size() << "\n";

    return 0;
}