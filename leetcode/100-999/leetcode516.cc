#include <iostream>
using namespace std;
class Solution {
public:
    int dp[1005][1005] = {};
    int solve(string& s, int left, int right)
    {
        if (left > right)
            return 0;
        if (dp[left][right])
            return dp[left][right];
        if (left == right)
            return dp[left][right] = 1;
        else if (s[left] == s[right]) {
            return dp[left][right] = 2 + solve(s, left + 1, right - 1);
        } else {
            return dp[left][right]
                = max(solve(s, left + 1, right), solve(s, left, right - 1));
        }
    }
    int longestPalindromeSubseq(string s)
    {
        int len = s.length();
        for (int i = 1; i <= len; i++)
            dp[i][i] = 1;
        return solve(s, 0, len - 1);
    }
};
int main(void) { return 0; }