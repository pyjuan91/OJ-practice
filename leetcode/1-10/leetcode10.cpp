#include <algorithm>
#include <cstdbool>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     bool isMatch(string s, string p)
//     {
//         int i = s.length() - 1, j = p.length() - 1, val;
//         for (; j >= 0; j--) {
//             // cout << "i: " << i << " j: " << j << endl;
//             // cout << "s[i]: " << s[i] << " p[i]: " << p[j] << endl;
//             if (i == -1) {
//                 return checkNullHead(p, j);
//             }
//             if (p[j] >= 'a' && p[j] <= 'z') {
//                 if (s[i] != p[j])
//                     return false;
//                 else
//                     i--;
//             } else if (p[j] == '.') {
//                 i--;
//             } else {
//                 val = star(s, p, i, j);
//                 if (val == 1)
//                     return true;
//             }

//         }
//         return i == -1;
//     }
//     int star(string& s, string& p, int& i, int& j)
//     {
//         if (j > 0 && p[j - 1] == '.') {
//             if (j - 1 == 0)
//                 return 1;
//             else {
//                 j -= 2;
//                 star(s, p, i, j);
//             }
//         } else {
//             while (i >= 0 && s[i] == p[j - 1]) {
//                 i--;
//             }
//             j -= 1;
//         }
//         return 0;
//     }

//     bool checkNullHead(string p, int j)
//     {
//         for (; j >= 0; j--) {
//             if (p[j] != '*')
//                 return false;
//             else
//                 j--;
//         }
//         return true;
//     }
// };

class Solution {
private:
    bool dp[35][35];
    bool canBeNull[35];

public:
    bool isMatch(string s, string p)
    {
        for (int i = 0; i < 35; i++) {
            for (int j = 0; j < 35; j++) {
                dp[i][j] = false;
            }
        }

        int m = s.length(), n = p.length();

        for (int i = 0; i < n; i++) {
            if (p[i] != '*')
                canBeNull[i] = false;
            else {
                if (i == 1)
                    canBeNull[i] = true;
                else
                    canBeNull[i] = canBeNull[i - 2];
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << canBeNull[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[j] != '*') {

                    if (i > 0 && j > 0) {
                        dp[i][j] = (dp[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.'));
                        continue;
                    }
                    if (i == 0 && j > 0) {
                        dp[i][j] = canBeNull[j - 1] && (s[i] == p[j] || p[j] == '.');
                        // cout << "i: " << i << " j: " << j << endl;
                        // cout << "canbe: " << canBeNull[j - 1] << endl;
                        // cout << dp[i][j] << endl;
                        continue;
                    }
                    dp[0][0] = (s[0] == p[0] || p[0] == '.');
                    // cout << "i: " << i << " j: " << j << endl;
                    // cout << dp[i][j] << endl;
                    continue;

                } else {

                    if (i > 0 && j > 0) {
                        // zero
                        dp[i][j] = (j > 1 && dp[i][j - 2])
                            || (dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                        continue;
                    }
                    if (i == 0) {
                        dp[i][j] = (j > 1 && dp[i][j - 2])
                            || ((j == 1 || canBeNull[j - 2]) && (s[i] == p[j - 1] || p[j - 1] == '.'));
                        // cout << "i: " << i << " j: " << j << endl;
                        // cout << dp[i][j] << endl;
                        continue;
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main(void)
{
    Solution S;
    string s = "a";
    string p = ".*..a*";
    cout << S.isMatch(s, p) << endl;
    return 0;
}