#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		vector<bool> vist(n, false);
		int cur_num = 0;
		for (auto& x : a) cin >> x;
		for (int i = 1; i <= min(32ll, n); i++) {
			int max_test = 0, max_index = -1;
			for (int j = 0; j < n; j++) {
				if (vist[j]) continue;
				if ((a[j] | cur_num) > max_test) {
					max_test = (a[j] | cur_num);
					max_index = j;
				}
			}
			if (max_index != -1) {
				vist[max_index] = true;
				cout << a[max_index] << " ";
				cur_num = max_test;
			}
		}
		for (int i = 0; i < n; i++)
			if (!vist[i]) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}