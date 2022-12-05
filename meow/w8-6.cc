#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void traverse(vector<vector<int>>& node, vector<bool>& used,
    int now)
{
    used[now] = true;
    for (auto i : node[now]) {
        if (used[i] == false) {
            traverse(node, used, i);
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y, z, res = 0;
    cin >> n >> m;
    vector<vector<int>> node(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        node[x].emplace_back(y);
        node[y].emplace_back(x);
    }
    vector<bool> used(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            res += 1;
            traverse(node, used, i);
        }
    }
    cout << res << endl;
    return 0;
}