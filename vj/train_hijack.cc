#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n;
		vector<int> end_with_max(n + 1), end_with_min(n + 1);
		end_with_max[0] = end_with_min[0] = 1;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			if (x == 0) end_with_max[i] = end_with_min[i] = 0;
			else if (x > 0) {
				end_with_max[i] = max(x, end_with_max[i - 1] * x);
				end_with_min[i] = min(x, end_with_min[i - 1] * x);
			}
			else {
				end_with_max[i] = max(x, end_with_min[i - 1] * x);
				end_with_min[i] = min(x, end_with_max[i - 1] * x);
			}
		}
		cout
		  << "Case " << kase << ": "
		  << *max_element(end_with_max.begin() + 1, end_with_max.end())
		  << '\n';
	}
	return 0;
}
