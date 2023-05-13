#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, x, prefix_sum = 0, res = 0, a;
	map<int, int> m;
	m[0] = 1;
	cin >> n >> x;
	while (n--) {
		cin >> a;
		prefix_sum += a;
		if (m.count(prefix_sum - x)) res += m[prefix_sum - x];
		m[prefix_sum] += 1;
	}
	cout << res << "\n";
	return 0;
}