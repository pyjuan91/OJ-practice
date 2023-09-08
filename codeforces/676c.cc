#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	int cnt , l , res = 0;
	auto chaewon = [&](char c) {
		cnt = 0, l = 0;
		for (int r = 0; r < n; r++) {
			if (s[r] == c) cnt++;
			if (cnt > k) {
				while (s[l] != c) l++;
				l++;
				cnt--;
			}
			res = max(res, r - l + 1);
		}
	};
	chaewon('a');
	chaewon('b');
	cout << res << '\n';
	return 0;
}
