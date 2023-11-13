#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	auto confuse = [&]() {
		for (int i = 0; i < min(n, m); i++) {
			int x = s1[i] - '0', y = s2[i] - '0';
			if (x + y >= 10) return true;
		}
		return false;
	};
	cout << (confuse() ? "Yes" : "No") << '\n';
	return 0;
}
