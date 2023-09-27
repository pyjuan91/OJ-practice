#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, table;
	unordered_set<string> st;
	int k, res = 0;
	cin >> s >> table >> k;
	for (int len = 1; len <= s.length(); len++) {
		int left = 0, right = len, bad = 0;
		for (int i = 0; i < len; i++) {
			if (table[s[i] - 'a'] == '0') bad++;
		}
		while (right <= s.length()) {
			if (bad <= k) { st.insert(s.substr(left, len)); }
			if (right == s.length()) break;
			if (table[s[left++] - 'a'] == '0') bad--;
			if (table[s[right++] - 'a'] == '0') bad++;
		}
        res += st.size();
        st.clear();
	}
    cout << res << '\n';
	return 0;
}
