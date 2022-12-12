#include <iostream>
using namespace std;
class Solution {
public:
    int dp[30005] = {};
    int longestValidParentheses(string s)
    {
        int len = s.length(), res = 0;
        // dp: end at i's longest valid parentheses
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                int last_start = i - dp[i - 1];
                if (last_start && s[last_start - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (last_start - 1 ? dp[last_start - 2] : 0);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};
int main(void) { return 0; }