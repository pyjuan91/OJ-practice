#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = 10005;
        int maxpro = 0;
        for (auto i : prices)
        {
            mini = min(mini, i);
            maxpro = max(maxpro, i-mini);
        }
        return maxpro;
    }
};
int main(void)
{
    Solution s;
    vector<int> v;
    v.push_back(7);
    v.push_back(6);
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    // v.push_back(4);
    cout << s.maxProfit(v) << endl;
    return 0;
}