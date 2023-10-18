#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, cnt[26] = {};
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> c, cnt[c - 'a']++;
	}
	bool n_odd = n & 1, m_odd = m & 1;
	if (!n_odd && !m_odd) {
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 4 != 0) {
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
		return 0;
	}

	if (n_odd && !m_odd) {
		int forced_mid = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2 != 0) {
				cout << "No";
				return 0;
			}
			if (cnt[i] % 4 != 0) forced_mid++;
		}
		if (forced_mid > m / 2) {
			cout << "No";
			return 0;
		}
		cout << "Yes";
		return 0;
	}
	if (!n_odd && m_odd) {
		int forced_mid = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2 != 0) {
				cout << "No";
				return 0;
			}
			if (cnt[i] % 4 != 0) forced_mid++;
		}
		if (forced_mid > n / 2) {
			cout << "No";
			return 0;
		}
		cout << "Yes";
		return 0;
	}
	int odd_cnt = 0, forced_mid = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2 != 0) {
			odd_cnt++;
			if ((cnt[i] - 1) % 4 != 0) forced_mid++;
		}
		else if (cnt[i] % 4 != 0) forced_mid++;
	}
    if (odd_cnt != 1) {
        cout << "No";
        return 0;
    }
    if (forced_mid > (n / 2) + (m / 2)) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
	return 0;
}
