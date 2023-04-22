#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = -1, i = 0;
	string s;
	cin >> n >> s;
	for (i = 0; i < n; i++) {
		int cur = 0;
		while (i < n && s[i] == 'o') {
			i += 1;
			cur += 1;
		}
		auto con1 = i - 1 - cur >= 0 && s[i - 1 - cur] == '-';
		auto con2 = i < n && s[i] == '-';
		if (con1 || con2) res = max(res, cur);
	}
	if (res) cout << res;
	else cout << -1;
	return 0;
}