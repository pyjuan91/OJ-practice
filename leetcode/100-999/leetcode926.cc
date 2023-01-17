#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int len = s.length();
        vector<vector<int>> dp(len + 1, vector<int>(2));

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = min(dp[i][0] + 1, dp[i][1] + 1);
            } else {
                dp[i + 1][0] = dp[i][0] + 1;
                dp[i + 1][1] = min(dp[i][0], dp[i][1]);
            }
        }

        return min(dp[len][0], dp[len][1]);
    }
};
int main(void) { return 0; }