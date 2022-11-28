#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, int> win, lose;
        for (auto i : matches) {
            win[i[0]] += 1;
            lose[i[1]] += 1;
        }
        vector<int> one, two;
        for (auto i : win) {
            if (lose.find(i.first) == lose.end())
                one.emplace_back(i.first);
        }
        for (auto i : lose) {
            if (i.second == 1)
                two.emplace_back(i.first);
        }
        vector<vector<int>> res = { one, two };

        return res;
    }
};
int main(void)
{
    vector<vector<int>> matches = { { 1, 3 }, { 2, 3 }, { 3, 3 } };
    Solution s;
    s.findWinners(matches);

    return 0;
}