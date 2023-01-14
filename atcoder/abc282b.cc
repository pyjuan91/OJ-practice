#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, m, res = 0;
    cin >> n >> m;
    char c;
    vector<vector<bool>> v(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            v[i][j] = (c == 'o');
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool pairable = true;
            for (int k = 0; k < m; k++) {
                pairable = pairable && (v[i][k] || v[j][k]);
            }
            if (pairable)
                res += 1;
        }
    }
    cout << res;
    return 0;
}