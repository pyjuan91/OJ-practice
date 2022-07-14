#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> dp = cost;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};
int main(void)
{
    return 0;
}