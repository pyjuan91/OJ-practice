#include <bits/stdc++.h>
using namespace std;
#define int long long
void chaewon(vector<int>& a, vector<int>& b, int& n) {
	vector<int> prefix(n), whole_prefix(n), remain(n);
	prefix[0] = b[0];
	for (int i = 1; i < n; i++)
		prefix[i] = b[i] + prefix[i - 1];
	for (int i = 0; i < n; i++) {
		int pos = upper_bound(
					begin(prefix), end(prefix),
					a[i] + (i ? prefix[i - 1] : 0))
				- begin(prefix);
		whole_prefix[i] += 1;
		if (pos < n) {
			whole_prefix[pos] -= 1;
			remain[pos]
			  += a[i]
			   - (pos ? prefix[pos - 1] - (i ? prefix[i - 1] : 0) : 0);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] * whole_prefix[i] + remain[i] << " ";
		if (i < n - 1) whole_prefix[i + 1] += whole_prefix[i];
	}
	cout << endl;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		chaewon(a, b, n);
	}
	return 0;
}