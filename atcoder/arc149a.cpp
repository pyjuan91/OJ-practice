#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    P ans = { 0, 0 };
    cin >> n >> m;

    for (int i = 1; i < 10; i++) {
        int remain = 0;
        for (int j = 1; j <= n; j++) {
            remain *= 10;
            remain += i;
            remain %= m;
            if (remain % m == 0)
                ans = max(ans, { j, i });
        }
    }

    if (ans.first == 0)
        cout << "-1\n";
    else {
        for (int i = 0; i < ans.first; i++)
            cout << ans.second;
        cout << "\n";
    }

    return 0;
}