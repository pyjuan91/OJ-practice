#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 6e5 + 5, base = 7, mod = 1e15 + 7;
int n, m, pw[maxn];

void init_pw() {
	pw[0] = 1;
	for (int i = 1; i < maxn; i++) {
		pw[i] = pw[i - 1] * base % mod;
	}
}

int get_hash(const string& s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = (res * base % mod + s[i]) % mod;
	}
	return res;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	init_pw();
	cin >> n >> m;
	set<int> s;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		s.insert(get_hash(str));
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		int h = get_hash(str);
		bool ok = false;
		for (int j = 0; j < str.size(); j++) {
			for (char c : {'a', 'b', 'c'}) {
				if (c == str[j]) continue;
				int nh = (h + (c - str[j]) * pw[str.size() - j - 1] % mod + mod)
					   % mod;
				if (s.count(nh)) {
					ok = true;
					break;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
	return 0;
}