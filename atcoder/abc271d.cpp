// #include <bits/stdc++.h>
// using namespace std;
// int n, s, a[105], b[105];
// char seq[105];
// void input(void)
// {
//     cin >> n >> s;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i] >> b[i];
//     }
// }
// bool solve(int cur, int sum)
// {
//     if (cur == n) {
//         return sum == s;
//     }

//     if (sum + a[cur] <= s) {
//         seq[cur] = 'H';
//         if (solve(cur + 1, sum + a[cur]))
//             return true;
//         seq[cur] = 'X';
//     }
//     if (sum + b[cur] <= s) {
//         seq[cur] = 'T';
//         if (solve(cur + 1, sum + b[cur]))
//             return true;
//         seq[cur] = 'X';
//     }

//     return false;
// }
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     input();
//     if (solve(0, 0)) {
//         cout << "Yes\n";
//         for (int i = 0; i < n; i++)
//             cout << seq[i];
//         cout << "\n";
//     } else
//         cout << "No\n";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, s, a[105], b[105];
bool dp[105][100005] = { false };
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i] && dp[i - 1][j - a[i]]) {
                dp[i][j] = true;
            } else if (j >= b[i] && dp[i - 1][j - b[i]]) {
                dp[i][j] = true;
            } else
                dp[i][j] = false;
            // cout << "i: " << i << " j: " << j << " " << dp[i][j] << endl;
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= s; j++) {
    //         cout << "i: " << i << " j: " << j << " " << dp[i][j] << endl;
    //     }
    // }
    if (dp[n][s]) {
        cout << "Yes\n";
        char str[n + 1];
        str[n] = '\0';
        for (int i = n - 1; i >= 0; i--) {
            if ((s - a[i + 1] >= 0) && dp[i][s - a[i + 1]]) {
                str[i] = 'H';
                s -= a[i + 1];
            } else {
                str[i] = 'T';
                s -= b[i + 1];
            }
        }
        cout << str << "\n";
    } else
        cout << "No\n";

    return 0;
}