#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n, a[105], b[105], g[105], guess[4] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> g[i];
    for (int i = 1; i <= 3; i++) {
        int state[4] = {};
        state[i] = 1;
        for (int j = 0; j < n; j++) {
            swap(state[a[j]], state[b[j]]);
            if (state[g[j]])
                guess[i] += 1;
        }
    }
    cout << max({ guess[1], guess[2], guess[3] });
    return 0;
}