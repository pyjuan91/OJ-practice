#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt[10] = {}, ma = INT32_MIN, res;
	for (auto c : s) cnt[c - '0']++;
	for (int i = 0; i < 10; i++) {
		if (cnt[i] > ma) {
			ma = cnt[i];
			res = i;
		}
	}
	cout << res;
	return 0;
}
