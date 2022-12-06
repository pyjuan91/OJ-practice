#include <iostream>
using namespace std;
class Solution {
public:
    int dp[1005][1005] = {};
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length(), m = text2.length();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    dp[i][j] = max({ dp[i][j], dp[i - 1][j], dp[i][j - 1] });
            }
        }
        return dp[n][m];
    }
};
int main(void) { return 0; }