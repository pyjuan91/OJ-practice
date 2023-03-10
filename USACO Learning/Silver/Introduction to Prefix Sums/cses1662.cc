#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, res = 0, prefix_sum = 0, x;
	cin >> n;
	map<int, int> m;
	m[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		prefix_sum = ((prefix_sum + x) % n + n) % n;
		res += m[prefix_sum];
		m[prefix_sum] += 1;
	}
	cout << res << "\n";
	return 0;
}