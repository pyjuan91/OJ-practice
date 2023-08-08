#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int id = -1;
		for (int i = 0; i < (int) s.length(); i++) {
			if (s[i] >= '5') {
				id = i;
				break;
			}
		}
		if (id == -1) {
			cout << s << '\n';
			continue;
		}
		int propogate = 1;
		for (int i = id; i < (int) s.length(); i++) s[i] = '0';
		id--;
		while (id >= 0) {
			if (s[id] >= '4') {
				s[id--] = '0';
				propogate = 1;
			}
			else {
				s[id] += propogate;
				propogate = 0;
				break;
			}
		}
		if (propogate) { cout << '1'; }
		cout << s << '\n';
	}
	return 0;
}
