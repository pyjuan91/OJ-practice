#include <bits/stdc++.h>
#define int long long
using namespace std;
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool is_prime(int n) {
	for (int i = 0; i < 11; ++i) {
		if (n == prime[i]) return true;
	}
	return false;
}
void chaewon(size_t n, int cur, vector<int>& v, vector<bool>& used) {
	if (v.size() == n) {
		if (!is_prime(v.back() + 1)) return;
		cout << 1;
		for (size_t i = 1; i < n; i++) cout << ' ' << v[i];
        cout << '\n';
		return;
	}
	if (cur > (int)n) return;
	for (size_t i = 2; i <= n; i++) {
		if (used[i]) continue;
		if (is_prime(i + v.back())) {
			used[i] = true;
			v.push_back(i);
			chaewon(n, cur + 1, v, used);
			used[i] = false;
			v.pop_back();
		}
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, kase = 1;
	vector<int> v = {1};
	while (cin >> n) {
		if (kase > 1) cout << '\n';
		vector<bool> used(n + 1, false);
		cout << "Case " << kase++ << ":\n";
		chaewon(n, 2, v, used);
	}
	return 0;
}
