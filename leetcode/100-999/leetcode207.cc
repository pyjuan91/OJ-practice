#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool toposort(int n, vector<int>& indgree, vector<vector<int>>& g)
    {
        vector<int> ans;
        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (indgree[u] == 0)
                q.emplace(u);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.emplace_back(u);
            for (auto v : g[u]) {
                if (--indgree[v] == 0)
                    q.emplace(v);
            }
        }
        return ans.size() == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indgree(numCourses, 0);
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto i : prerequisites) {
            indgree[i[1]] += 1;
            g[i[0]].emplace_back(i[1]);
        }
        return toposort(numCourses, indgree, g);
    }
};
int main(void) { return 0; }