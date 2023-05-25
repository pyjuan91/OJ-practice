#include <bits/stdc++.h>
using namespace std;
double chaewon(vector<vector<int>>& tree, int n, int cur, int prev) {
	double res = 0;
	int count = 0;
	for (auto child : tree[cur]) {
		if (child != prev) {
			count += 1;
			res += chaewon(tree, n, child, cur);
		}
	}
	if (count == 0) return 1;
	return res / count + 1;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	vector<vector<int>> t(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		t[a].emplace_back(b);
		t[b].emplace_back(a);
	}
	cout << setprecision(15) << chaewon(t, n, 1, 0) - 1 << "\n";
	return 0;
}