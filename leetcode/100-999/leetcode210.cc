#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ans;
    bool topo(int n, vector<int>& indgree, vector<vector<int>>& g)
    {
        ans.clear();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indgree[i] == 0)
                q.emplace(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.emplace_back(cur);
            for (auto next : g[cur]) {
                if (indgree[next] == 0)
                    return false;
                indgree[next] -= 1;
                if (indgree[next] == 0) {
                    q.emplace(next);
                }
            }
        }
        return ans.size() == n;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indgree(numCourses, 0);
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto i : prerequisites) {
            indgree[i[0]] += 1;
            g[i[1]].emplace_back(i[0]);
        }
        if (topo(numCourses, indgree, g))
            return ans;
        return vector<int>();
    }
};
int main(void)
{
    return 0;
}