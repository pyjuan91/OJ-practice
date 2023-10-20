#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge {
		int e, b, c;
		Edge(int e, int b, int c)
		  : e(e)
		  , b(b)
		  , c(c) {}
		Edge() {}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c, d;
	cin >> n >> m;
	vector<vector<Edge>> g(n + 1);
	while (m--) {
		cin >> a >> b >> c >> d;
		g[a].push_back(Edge(b, c, d));
	}
	double left = 0, right = 2e10, mid;
	while (right - left > 1e-10) {
		mid = (left + right) / 2;
		vector<double> dist(n + 1, -1e18);
		dist[1] = 0;
		for (int i = 1; i < n; i++) {
			for (auto e : g[i]) {
				dist[e.e] = max(dist[e.e], (dist[i] + e.b) - mid * e.c);
			}
		}
		if (dist[n] < 0) right = mid;
		else left = mid;
	}
	cout << fixed << setprecision(12) << left;
	return 0;
}