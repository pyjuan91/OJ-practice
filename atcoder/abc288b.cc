#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.begin() + m);
	for (int i = 0; i < m; i++) {
		cout << a[i] << "\n";
	}
	return 0;
}