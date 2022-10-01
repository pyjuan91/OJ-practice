#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, l, s, t, member;
    vector<vector<int>> v;
    cin >> n >> q;
    while (n--) {
        vector<int> e;
        cin >> l;
        while (l--) {
            cin >> member;
            e.push_back(member);
        }
        v.push_back(e);
    }
    while (q--) {
        cin >> s >> t;
        cout << v[s - 1][t - 1] << "\n";
    }
    return 0;
}