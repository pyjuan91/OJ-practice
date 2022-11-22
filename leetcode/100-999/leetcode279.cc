#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++)
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            // for (int j = 1; j <= n; j++)
            //     printf("%3d ", dp[j]);
            // cout << endl;
        }
        return dp[n];
    }
};
int main(void)
{

    Solution s;
    cout << s.numSquares(20) << endl;

    return 0;
}