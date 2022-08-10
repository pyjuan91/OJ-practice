#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
int G[maxn][maxn], c[maxn], topo[maxn], t;
int n, m, i, j;
void clearG(void)
{
    for (i = 0; i < maxn; i++) {
        for (j = 0; j < maxn; j++) {
            G[i][j] = 0;
        }
    }
}
bool dfs(int u)
{
    c[u] = -1;
    for (int v = 1; v <= n; v++) {
        if (G[u][v]) {
            if (c[v] < 0) {
                return false;
            } else if (!c[v] && !dfs(v)) {
                return false;
            }
        }
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}
bool toposort()
{
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 1; u <= n; u++) {
        if (!c[u]) {
            if (!dfs(u))
                return false;
        }
    }
    return true;
}
int main(void)
{
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        clearG();
        while (m--) {
            cin >> i >> j;
            G[i][j] = 1;
        }
        if (toposort()) {
            for (i = 0; i < n; i++) {
                cout << topo[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}