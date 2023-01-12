#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(int root, int pre, vector<vector<int>>& edges,
        char target, vector<int>& res, string& labels, vector<bool>& complete)
    {
        int sum = 0;
        for (auto i : edges[root]) {
            if (i == pre)
                continue;
            sum += dfs(i, root, edges, target, res, labels, complete);
        }
        if (labels[root] == target) {
            complete[root] = true;
            return res[root] = sum + 1;
        }
        return sum;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<int> res(n, 1);
        queue<pair<int, int>> q;
        vector<vector<int>> e(n);
        vector<bool> complete(n, false);
        for (auto i : edges) {
            e[i[0]].emplace_back(i[1]);
            e[i[1]].emplace_back(i[0]);
        }
        q.push({ 0, -1 });
        while (q.size()) {
            int root = q.front().first;
            int pre = q.front().second;
            q.pop();
            if (complete[root] == false)
                dfs(root, pre, e, labels[root], res, labels, complete);
            for (auto i : e[root]) {
                if (i == pre)
                    continue;
                q.push({ i, root });
            }
        }
        return res;
    }
};
int main(void)
{
    Solution s;
    int n = 6;
    vector<vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 3, 4 }, { 4, 5 } };
    string labels = "cbabaa";

    s.countSubTrees(n, edges, labels);

    return 0;
}