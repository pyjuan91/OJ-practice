#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int res = 0, n = s.length();
	vector<int> pre_b_cnt(n + 1, 0);
	for (int i = 0; i < n; i++)
		pre_b_cnt[i + 1] = pre_b_cnt[i] + (s[i] == 'B');
	for (int i = 0; i < n; i++)
		if (s[i] == 'W') res += pre_b_cnt[i];
	cout << res << '\n';
	return 0;
}
