#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int root, int pre, vector<vector<int>>& e, vector<bool>& a)
    {
        int res = 0, child;
        for (auto i : e[root]) {
            if (i == pre)
                continue;
            child = dfs(i, root, e, a);
            if (child || a[i])
                res += 2 + child;
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<vector<int>> e(n);
        for (auto i : edges) {
            e[i[0]].emplace_back(i[1]);
            e[i[1]].emplace_back(i[0]);
        }
        return dfs(0, -1, e, hasApple);
    }
};
int main(void) { return 0; }