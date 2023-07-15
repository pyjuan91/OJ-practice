#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], t, n, m;
bool possess[maxn];
vector<int> fac[maxn];

bool guess(int mid) {
	if (mid < 0) return false;
	vector<int> cnt(m + 1, 0);
	int cur = 0, lb = 0;
	for (int rb = 0; rb < n; rb++) {
		for (auto& f : fac[a[rb]]) {
			if (cnt[f] == 0) cur++;
			cnt[f]++;
		}
		while (a[rb] - a[lb] > mid) {
			for (auto& f : fac[a[lb]]) {
				cnt[f]--;
				if (cnt[f] == 0) cur--;
			}
			lb++;
		}
		if (cur == m) return true;
	}
	return false;
}

int chaewon() {
	for (int j = 1; j <= m; j++)
		for (int i = j; i <= a[n - 1]; i += j)
			if (possess[i]) fac[i].push_back(j);

	int left = -1, right = a[n - 1] - a[0], mid;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		if (guess(mid)) right = mid;
		else left = mid;
	}
	if (guess(right)) return right;
	return -1;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(possess, false, sizeof(possess));
		for (int i = 0; i < n; i++)
			cin >> a[i], possess[a[i]] = true, fac[a[i]].clear();
		sort(a, a + n);
		cout << chaewon() << "\n";
	}
	return 0;
}