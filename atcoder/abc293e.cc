#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>>
	mat_mul(vector<vector<ll>>& res, vector<vector<ll>>& mat, ll m) {
	vector<vector<ll>> ans(2, vector<ll>(2, 0ll));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				ans[i][j] += res[i][k] * mat[k][j];
			ans[i][j] %= m;
		}
	}
	return ans;
}
vector<vector<ll>>
	fast_mat_mul(vector<vector<ll>>& mat, ll m, ll x) {
	vector<vector<ll>> res = {{1, 0}, {0, 1}};
	while (x) {
		if (x & 1) res = mat_mul(res, mat, m);

		x >>= 1;
		mat = mat_mul(mat, mat, m);
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	ll a, x, m;
	cin >> a >> x >> m;
	vector<vector<ll>> mat = {{a, 1ll}, {0ll, 1ll}};
	mat = fast_mat_mul(mat, m, x);
	cout << mat[0][1];
	return 0;
}