#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll N, K, res = 0;
vector<vector<ll>>
  matrix_multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	auto res = vector<vector<ll>>(N, vector<ll>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
	return res;
}
vector<vector<ll>>
  matrix_fast_power(vector<vector<ll>>& g, ll power = K) {
	auto res = vector<vector<ll>>(N, vector<ll>(N, 0));
	for (int i = 0; i < N; i++) res[i][i] = 1;
	while (power) {
		if (power & 1) res = matrix_multiply(res, g);
		g = matrix_multiply(g, g);
		power >>= 1;
	}
	return res;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> N >> K;
	vector<vector<ll>> g(N, vector<ll>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> g[i][j];
	g = matrix_fast_power(g);
	for (auto i : g)
		for (auto j : i) res = (res + j) % mod;
	cout << res;
	return 0;
}