#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> inDegree;
vector<int> ans;
bool topology(int n)
{
    ans.clear();
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.emplace_back(cur);
        for (auto i : graph[cur]) {
            inDegree[i] -= 1;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans.size() == n;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;

    graph = vector<vector<int>>(n + 1, vector<int>());
    inDegree = vector<int>(n + 1, 0);

    while (m--) {
        cin >> a >> b;
        graph[a].emplace_back(b);
        inDegree[b] += 1;
    }

    if (topology(n)) {
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}