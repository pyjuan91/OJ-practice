#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, x, res = 0;
	cin >> n >> x;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	map<int, int> table;
	for (int i = 0; i <= n; i++) {
        res += table[a[i] - x];
		table[a[i]] += 1;
	}

	cout << res << "\n";
	return 0;
}