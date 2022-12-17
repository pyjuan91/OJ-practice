#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> route;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        route.emplace_back(make_pair(a, b));
    }
    sort(route.begin(), route.end());
    set<int, greater<int>> s;
    for (int i = 0; i < n; i++) {
        auto iter = s.lower_bound(route[i].second);
        if (iter != s.end())
            s.erase(iter);
        s.insert(route[i].second);
    }
    cout << s.size() << endl;
    return 0;
}