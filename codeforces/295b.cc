#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x, g[505][505];
vector<int> res, seq, cur;

void chaewon(int mid) {
	int su = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = min(g[i][j], g[i][mid] + g[mid][j]);
	for (auto start : cur)
		for (auto end : cur) su += g[start][end];
	res.emplace_back(su);
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> g[i][j];
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		seq.push_back(x);
	}
	reverse(seq.begin(), seq.end());
	for (int k = 0; k < n; k++) {
		cur.push_back(seq[k]);
		chaewon(seq[k]);
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
	return 0;
}
