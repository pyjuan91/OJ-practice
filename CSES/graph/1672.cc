#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q, a, b, c;
    cin>>n>>m>>q;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e18));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    while (m--) {
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while (q--) {
        cin>>a>>b;
        cout<<(dist[a][b] == 1e18 ? -1 : dist[a][b])<<'\n';
    }
	return 0;
}