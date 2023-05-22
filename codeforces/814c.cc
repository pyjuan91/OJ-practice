#include <bits/stdc++.h>
using namespace std;
int chaewon(int& n, string& s, int& m, char& c) {
	int left = 0, not_c = 0, res = 0;
	for (int right = 0; right < n; right++) {
		if (s[right] != c) {
			not_c += 1;
			while (not_c > m) {
				if (s[left] != c) not_c -= 1;
				left += 1;
			}
		}
		res = max(right - left + 1, res);
	}
	return res;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, q, m;
	string s;
	char c;
	cin >> n >> s >> q;
	while (q--) {
		cin >> m >> c;
		cout << chaewon(n, s, m, c) << "\n";
	}
	return 0;
}