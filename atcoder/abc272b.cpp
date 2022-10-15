#include <bits/stdc++.h>
using namespace std;
int Map[105][105] = { 0 };
int main(void)
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        vector<int> v(k);
        for (int j = 0; j < k; j++) {
            cin >> v[j];
        }
        for (int j = 0; j < k; j++) {
            for (int q = 0; q < k; q++) {
                Map[v[j]][v[q]] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (Map[i][j] == 0) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}