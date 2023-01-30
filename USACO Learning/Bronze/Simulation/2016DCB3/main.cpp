#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ::freopen("cowsignal.in", "r", stdin);
    ::freopen("cowsignal.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    char c;
    cin >> n >> m >> k;
    vector<vector<char>> g(k * n, vector<char>(k * m));
    for (int i = 0; i < k * n; i += k) {
        for (int j = 0; j < k * m; j += k) {
            cin >> c;
            for (int l = 0; l < k; l++)
                for (int r = 0; r < k; r++)
                    g[i + l][j + r] = c;
        }
    }
    for (int i = 0; i < k * n; i++) {
        for (int j = 0; j < k * m; j++) {
            cout << g[i][j];
        }
        cout << "\n";
    }
    return 0;
}