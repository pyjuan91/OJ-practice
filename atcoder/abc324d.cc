#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0, cnt[10] = {};
	string s;
	cin >> n >> s;
	for (auto i : s) cnt[i - '0']++;
	for (int i = 0; i <= 3162278; i++) {
		int cur[10] = {};
		int x = i * i;
		while (x) {
			cur[x % 10]++;
			x /= 10;
		}
		bool ok = true;
		for (int j = 1; j < 10; j++) {
			if (cur[j] != cnt[j]) {
				ok = false;
				break;
			}
		}
		if (cur[0] > cnt[0]) ok = false;
		if (ok) res++;
	}
	cout << res;
	return 0;
}
