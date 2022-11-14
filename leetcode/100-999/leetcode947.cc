#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones)
    {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], ~stones[i][1]);
        return stones.size() - islands;
    }

    unordered_map<int, int> f;
    int islands = 0;

    int find(int x)
    {
        if (!f.count(x))
            f[x] = x, islands++;
        if (x != f[x])
            f[x] = find(f[x]);
        return f[x];
    }

    void uni(int x, int y)
    {
        x = find(x), y = find(y);
        if (x != y)
            f[x] = y, islands--;
    }
};
int main(void)
{
    Solution s;
    vector<vector<int>> stones = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 2, 1 }, { 2, 2 } };
    s.removeStones(stones);

    return 0;
}