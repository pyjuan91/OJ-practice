#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string a[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	int res = INT64_MAX;
	auto check = [&](char slot) {
		int res = 0;
		vector<int> cnt[3];
		for (int i = 0; i < 3 * n; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[j][i % n] == slot && cnt[j].size() < 3) {
					cnt[j].push_back(i);
				}
			}
		}
		for (int i = 0; i < 3; i++)
			if (cnt[i].size() == 0) return 1LL * INT64_MAX;
		if (cnt[0][0] == cnt[1][0] && cnt[1][0] == cnt[2][0]) {
			if (cnt[0][1] >= cnt[1][1] && cnt[0][1] >= cnt[2][1]) {
				if (cnt[1][1] == cnt[2][1])
					res = min(cnt[1][2], cnt[2][2]);
				else res = max(cnt[1][1], cnt[2][1]);
			}
			else if (cnt[1][1] >= cnt[0][1] && cnt[1][1] >= cnt[2][1]) {
				if (cnt[0][1] == cnt[2][1])
					res = min(cnt[0][2], cnt[2][2]);
				else res = max(cnt[0][1], cnt[2][1]);
			}
			else {
				if (cnt[0][1] == cnt[1][1])
					res = min(cnt[0][2], cnt[1][2]);
				else res = max(cnt[0][1], cnt[1][1]);
			}
		}
		else if (cnt[0][0] == cnt[1][0] && cnt[1][0] != cnt[2][0]) {
			res = max(cnt[2][0], min(cnt[0][1], cnt[1][1]));
		}
		else if (cnt[0][0] != cnt[1][0] && cnt[1][0] == cnt[2][0]) {
			res = max(cnt[0][0], min(cnt[1][1], cnt[2][1]));
		}
		else if (cnt[0][0] == cnt[2][0] && cnt[1][0] != cnt[2][0]) {
			res = max(cnt[1][0], min(cnt[0][1], cnt[2][1]));
		}
		else res = max({cnt[0][0], cnt[1][0], cnt[2][0]});
		return res;
	};

	for (char slot = '0'; slot <= '9'; slot++) {
		res = min(res, check(slot));
        // cout <<"slot: " << slot << " " << check(slot) << '\n';
	}
	if (res == INT64_MAX) cout << -1 << '\n';
	else cout << res << '\n';
	return 0;
}
