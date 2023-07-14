#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt[3] = {}, mi;
	for (auto& c : s) cnt[c - 'a']++;
	mi = min({cnt[0], cnt[1], cnt[2]});
	cnt[0] -= mi;
	cnt[1] -= mi;
	cnt[2] -= mi;
	if (cnt[0] > 1 || cnt[1] > 1 || cnt[2] > 1) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}