#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n, vector<int>& a) {
	map<int, int> last_sum_pos;
	int res = 0, prefix = 0, last_zero_pos = 0;
	last_sum_pos[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix += a[i];
		if (a[i] == 0) {
			last_sum_pos[prefix] = i;
			last_zero_pos = i;
		}
		else {
			if (last_sum_pos.count(prefix)) {
				int selected_index
				  = max(last_zero_pos + 1, last_sum_pos[prefix] + 2);
				res += i - selected_index + 1;
				last_sum_pos[prefix] = i;
				last_zero_pos = selected_index - 1;
			}
			else {
				res += i - last_zero_pos;
				last_sum_pos[prefix] = i;
			}
		}
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << chaewon(n, a);
	return 0;
}
