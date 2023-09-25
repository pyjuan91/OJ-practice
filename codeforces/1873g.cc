#include <bits/stdc++.h>
using namespace std;
int chaewon(string& s, int& len) {
	if (s[0] == 'B' || s[len - 1] == 'B')
		return count(s.begin(), s.end(), 'A');
	int b_cnt = 0, a_cnt = 0;
	vector<int> a_cons;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'B') {
			if (a_cnt) {
				a_cons.push_back(a_cnt);
				a_cnt = 0;
			}
			b_cnt++;
		}
		else a_cnt++;
	}
	if (a_cnt) a_cons.push_back(a_cnt);
	if (b_cnt < a_cons.size())
		return count(s.begin(), s.end(), 'A')
			 - *min_element(a_cons.begin(), a_cons.end());
	return count(s.begin(), s.end(), 'A');
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int len = s.length();
		cout << chaewon(s, len) << '\n';
	}
	return 0;
}
