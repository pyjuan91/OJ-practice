#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		string res = "";
		for (int i = 0; i < n; i++) {
			res.push_back(s[i]);
            int j = i;
			while (i + 1 < n && s[i + 1] != s[j]) i++;
			i++;
		}
        cout << res << "\n";
	}
	return 0;
}