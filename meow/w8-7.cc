#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int ans = -1;
void dfs(vector<vector<int>>& node, vector<int>& size,
    int now, int parent)
{
    size[now] = 1;
    int max_son_size = -1;
    for (auto i : node[now]) {
        if (i != parent) {
            dfs(node, size, i, now);
            size[now] += size[i];
            max_son_size = max(max_son_size, size[i]);
        }
    }
    max_son_size = max(max_son_size, (int)node.size() - 1 - size[now]);
    if (max_son_size <= ((int)node.size() - 1) / 2)
        ans = now;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    vector<vector<int>> node(n + 1, vector<int>());
    vector<int> size(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        node[a].emplace_back(b);
        node[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        dfs(node, size, i, 0);
        if (ans != -1)
            break;
    }
    cout << ans << endl;
    return 0;
}