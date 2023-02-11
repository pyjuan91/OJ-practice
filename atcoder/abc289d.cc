#include <bits/stdc++.h>
using namespace std;
int route[100005] = {};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, x;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		route[b[i]] = 2;
	}
	cin >> x;
	route[0] = 1;
	for (int i = 0; i <= x; i++) {
		if (route[i] != 1) continue;
		for (int j = 0; j < n; j++)
			if (i + a[j] <= x && route[i + a[j]] == 0)
				route[i + a[j]] = 1;
		if (route[x]) break;
	}
	if (route[x]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}