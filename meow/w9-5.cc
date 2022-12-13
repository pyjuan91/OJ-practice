#include <bits/stdc++.h>
using namespace std;
bool draw(vector<vector<int>>& g, vector<int>& colors, int n)
{
    for (int i = 1; i <= n; i++) {
        if (colors[i] != 0)
            continue;
        queue<int> q, c;
        q.push(i);
        c.push(1);
        colors[i] = 1;
        while (!q.empty()) {
            int cur_point = q.front();
            q.pop();
            int cur_colors = c.front();
            c.pop();
            for (auto j : g[cur_point]) {
                if (colors[j] == 0) {
                    colors[j] = 3 - cur_colors;
                    q.push(j);
                    c.push(3 - cur_colors);
                } else if (colors[j] == cur_colors)
                    return false;
            }
        }
    }
    return true;
}
bool dfs(int cur_point, int cur_color, vector<vector<int>>& g,
    vector<int>& colors)
{
    if (colors[cur_point])
        return colors[cur_point] == cur_color;
    for (auto i : g[cur_point]) {
        if (!dfs(i, 3 - cur_color, g, colors))
            return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> colors(n + 1);
    while (m--) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if (draw(g, colors, n)) {
        for (int i = 1; i <= n; i++)
            cout << colors[i] << " ";
        cout << "\n";
    } else {
        cout << "MANY\n";
    }

    return 0;
}