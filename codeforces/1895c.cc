#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Str {
		int len, pre[6], suf[6];
		Str() {
			len = 0;
			memset(pre, 0, sizeof(pre));
			memset(suf, 0, sizeof(suf));
		}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, cnt[6][6][50][50] = {};
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		vector<int> v;
		int su = 0, sz = s.length();
		for (auto c : s)
			v.emplace_back(c - '0'), su += v.back();
		int cur = 0;
		for (int i = 0; i < sz; i++) {
			cur += v[i];
			cnt[sz][i + 1][cur][su - cur]++;
		}
	}
	int ans = 0;
	// 1 <-> 1
	for (int i = 0; i < 50; i++) {
		ans += cnt[1][1][i][0] * cnt[1][1][i][0];
	}
	// 1 <-> 3
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i + j >= 50) break;
			ans += cnt[1][1][i][0] * cnt[3][1][j][i + j];
		}
	}
	// 1 <-> 5
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i + j >= 50) break;
			ans += cnt[1][1][i][0] * cnt[5][2][j][i + j];
		}
	}
	// 3 <-> 1
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i - j < 0) break;
			ans += cnt[3][2][i][j] * cnt[1][1][i - j][0];
		}
	}
	// 3 <-> 3
	for (int i = 0; i < 50; i++) {
		ans += cnt[3][3][i][0] * cnt[3][3][i][0];
	}
	// 3 <-> 5
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i + j >= 50) break;
			ans += cnt[3][3][i][0] * cnt[5][1][j][i + j];
		}
	}
	// 5 <-> 1
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i - j < 0) break;
			ans += cnt[5][3][i][j] * cnt[1][1][i - j][0];
		}
	}
	// 5 <-> 3
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i - j < 0) break;
			ans += cnt[5][4][i][j] * cnt[3][3][i - j][0];
		}
	}
	// 5 <-> 5
	for (int i = 0; i < 50; i++) {
		ans += cnt[5][5][i][0] * cnt[5][5][i][0];
	}
	// 2 <-> 2
	for (int i = 0; i < 50; i++) {
		ans += cnt[2][2][i][0] * cnt[2][2][i][0];
	}
	// 2 <-> 4
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i + j >= 50) break;
			ans += cnt[2][2][i][0] * cnt[4][1][j][i + j];
		}
	}
	// 4 <-> 2
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i - j < 0) break;
			ans += cnt[4][3][i][j] * cnt[2][2][i - j][0];
		}
	}
	// 4 <-> 4
	for (int i = 0; i < 50; i++) {
		ans += cnt[4][4][i][0] * cnt[4][4][i][0];
	}
	cout << ans << "\n";
	return 0;
}
