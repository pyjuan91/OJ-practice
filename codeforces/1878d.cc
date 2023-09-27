#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, q;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		s = " " + s;
		vector<int> l(m), r(m);
		for (int i = 0; i < m; i++) cin >> l[i];
		for (int i = 0; i < m; i++) cin >> r[i];
		cin >> q;
		vector<int> modi(q);
		for (int i = 0; i < q; i++) cin >> modi[i];
		sort(modi.begin(), modi.end());
		int modi_index = 0;
		for (int i = 0; i < m; i++) {
			int left_bound = l[i], right_bound = r[i];
			int mid = (left_bound + right_bound) / 2;
			vector<bool> is_modi(mid - left_bound + 1, false);
            // cout << "mid: " << mid << "\n";
            // cout << "size: " << is_modi.size() << "\n";
			while (modi_index < q && modi[modi_index] >= left_bound
				   && modi[modi_index] <= right_bound) {
                // cout << "modi_index: " << modi_index << "\n";
                // cout << "modi[modi_index]: " << modi[modi_index] << "\n";
				if (modi[modi_index] > mid)
					modi[modi_index] = right_bound - modi[modi_index] + left_bound;
				is_modi[modi[modi_index] - left_bound]
				  = !is_modi[modi[modi_index] - left_bound];
				modi_index++;
			}
			for (int i = 0; i < is_modi.size(); i++) {
				if (i) is_modi[i] = is_modi[i] ^ is_modi[i - 1];
				if (is_modi[i])
					swap(s[left_bound + i], s[right_bound - i]);
			}
		}
        cout << s.substr(1) << "\n";
	}
	return 0;
}
