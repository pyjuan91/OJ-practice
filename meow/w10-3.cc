#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005];
// int rec[3005][3005];
// int str_rec[3005];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int lens = s.length(), lent = t.length();
    dp[0][0] = 0;
    // for (int i = 0; i <= lens; i++) {
    //     str_rec[i] = i;
    // }
    for (int i = 1; i <= lens; i++) {
        for (int j = 1; j <= lent; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // rec[i][j] = i;
                // str_rec[i] = rec[i - 1][j - 1];
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    // str_rec[i] = rec[i - 1][j];
                    // str_rec[i] = str_rec[i - 1];
                    // rec[i][j] = rec[i - 1][j];

                } else {
                    dp[i][j] = dp[i][j - 1];
                    // str_rec[i] = rec[i][j - 1];
                    // rec[i][j] = rec[i][j - 1];
                }
            }
        }
    }

    // int cur = rec[lens][lent];
    // cout << cur << endl;
    // cout << endl;
    // for (int i = 0; i <= lens; i++)
    //     cout << str_rec[i] << " ";
    // cout << endl;
    // for (int i = 0; i <= lens; i++) {
    //     for (int j = 0; j <= lent; j++) {
    //         cout << rec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // vector<char> res;
    // while (cur != 0) {
    //     res.emplace_back(s[cur - 1]);
    //     cur = str_rec[cur];
    // }
    // string ans(res.rbegin(), res.rend());
    // cout << ans << "\n";
    // cout << str1 << "\n";
    int x = lens, y = lent;
    vector<char> ans;
    while (x && y) {
        if (dp[x - 1][y] == dp[x][y])
            x -= 1;
        else if (dp[x][y - 1] == dp[x][y])
            y -= 1;
        else {
            ans.emplace_back(s[x - 1]);
            x -= 1;
            y -= 1;
        }
    }
    string res(ans.rbegin(), ans.rend());
    cout << res << "\n";
    return 0;
}