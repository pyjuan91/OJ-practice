#include <bits/stdc++.h>
#define int long long
using namespace std;
bool match(int& n, int& m, vector<string>& a, vector<string>& b, int& x, int& y) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			auto mx = (x + i) % n;
			auto my = (y + j) % n;
			if (a[mx][my] != b[i][j]) return false;
		}
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (auto& s : a) cin >> s;
	for (auto& s : b) cin >> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == b[0][0] && match(n, m, a, b, i, j)) {
				cout << "Yes\n";
				return 0;
			}
	cout << "No\n";
	return 0;
}