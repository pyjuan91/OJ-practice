#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length(), i = 0, cnt, cur = 0, res = 0;
	while (i < n) {
		if (s[i] == '<') res += ++cur, i++;
		else {
			cnt = 0;
			while (i < n && s[i] == '>') {
				++cnt;
				++i;
			}
			if (cur >= cnt) res += cnt * (cnt - 1) / 2, cur = 0;
			else {
				res -= cur;
				res += cnt * (cnt + 1) / 2;
				cur = 0;
			}
		}
	}
	cout << res << '\n';
	return 0;
}
