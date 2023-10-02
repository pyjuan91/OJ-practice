#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q, x;
	char c;
	cin >> q;
	map<int, int> mp;
	mp[0] = 1;
	while (q--) {
		cin >> c >> x;
		if (c == '+') mp[x]++;
		else if (c == '-') {
			mp[x]--;
			if (mp[x] == 0) mp.erase(x);
		}
		else {
			int ideal = 0;
			for (int i = 30; i >= 0; i--) {
				if ((x & (1 << i)) == 0) ideal |= (1 << i);
				auto iter = mp.lower_bound(ideal);
				if (iter == mp.end() || (iter->first >> i) != (ideal >> i))
					ideal ^= (1 << i);
			}
			cout << (ideal ^ x) << '\n';
		}
	}
	return 0;
}
