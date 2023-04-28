#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, res;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		res = n - 1;
		for (int i = 0; i < s.length() - 2; i++)
			if (s[i] == s[i + 2]) res -= 1;
		cout << res << "\n";
	}
	return 0;
}