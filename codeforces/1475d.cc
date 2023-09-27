#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], b[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		vector<int> con1, con2;
		for (int i = 0; i < n; i++) {
			if (b[i] == 1) con1.push_back(a[i]);
			else con2.push_back(a[i]);
		}
		sort(con1.begin(), con1.end());
		sort(con2.begin(), con2.end());
		int res = 0, cur_mem = 0, last_one = -1, last_two = -1;
		while (!con1.empty() && !con2.empty()) {
			if ((double) con1.back() > (double) con2.back() / 2) {
				res++;
				last_one = con1.back();
				cur_mem += con1.back();
				con1.pop_back();
			}
			else {
				res += 2;
				last_two = con2.back();
				cur_mem += con2.back();
				con2.pop_back();
			}
			if (cur_mem >= m) {
				if (last_one != -1) {
					if (cur_mem - last_one >= m) {
						cout << res - 1 << '\n';
						goto end;
					}
				}
				if (last_two != -1) {
					if (
					  !con1.empty()
					  && cur_mem - last_two + con1.back() >= m) {
						cout << res - 1 << '\n';
						goto end;
					}
				}
				cout << res << '\n';
				goto end;
			}
		}
		while (!con1.empty()) {
			res++;
			cur_mem += con1.back();
			con1.pop_back();
			if (cur_mem >= m) {
				if (last_two != -1) {
					if (
					  !con1.empty()
					  && cur_mem - last_two + con1.back() >= m) {
						cout << res - 1 << '\n';
						goto end;
					}
				}
				cout << res << '\n';
				goto end;
			}
		}
		while (!con2.empty()) {
			res += 2;
			cur_mem += con2.back();
			con2.pop_back();
			if (cur_mem >= m) {
				if (last_one != -1) {
					if (cur_mem - last_one >= m) {
						cout << res - 1 << '\n';
						goto end;
					}
				}
				cout << res << '\n';
				goto end;
			}
		}
		cout << "-1\n";
	end:;
	}
	return 0;
}