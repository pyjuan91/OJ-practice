#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int ma = INT32_MIN, id = 0;
	while (id < s.length()) {
		int j = id;
		while (j < s.length() && s[j] == s[id]) j++;
		ma = max(ma, j - id);
        id = j;
	}
    if (ma >= 7) cout << "YES\n";
    else cout << "NO\n";
	return 0;
}
