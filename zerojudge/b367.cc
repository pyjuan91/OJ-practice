#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool checker = true;
        vector<vector<int>> g = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] != g[n - 1 - i][m - 1 - j])
                    checker = false;
        if (checker)
            cout << "go forward\n";
        else
            cout << "keep defending\n";
    }
}