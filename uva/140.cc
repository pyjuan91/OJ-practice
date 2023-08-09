#include <bits/stdc++.h>
using namespace std;
int cal_score(string &s, vector<int> &pos, vector<int> g[]) {
	int n = s.length(), ans = 0;
	for (int i = 0; i < n; i++) {
		int u = s[i] - 'A';
		for (int v : g[u]) {
			if (pos[v] != -1)
				ans = max(ans, abs(pos[u] - pos[v]));
		}
	}
	return ans;
}
void chaewon(
  int n, vector<int> g[], vector<char> &appear, vector<int> &pos,
  string &cur_cond, int &ans, string &ans_str) {
	if (cur_cond.length() == (size_t) n) {
		// cout << cur_cond << '\n';
		int neo_score = cal_score(cur_cond, pos, g);
		if (neo_score == ans) {
			if (cur_cond < ans_str) ans_str = cur_cond;
		}
		else if (neo_score < ans) {
			ans = neo_score;
			ans_str = cur_cond;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (pos[appear[i]-'A'] == -1) {
			pos[appear[i]-'A'] = cur_cond.length();
			cur_cond += appear[i];
			if (cal_score(cur_cond, pos, g) <= ans)
				chaewon(n, g, appear, pos, cur_cond, ans, ans_str);
			cur_cond.pop_back();
			pos[appear[i]-'A'] = -1;
		}
	}
}
int32_t main() {
	// cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	while (cin >> s && s != "#") {
		size_t len = s.length(), i = 0;
		vector<int> g[26];
		while (i < len) {
			int u = s[i] - 'A';
			i += 2;
			while (i < len && s[i] != ';') {
				int v = s[i] - 'A';
				g[u].emplace_back(v);
				g[v].emplace_back(u);
				i++;
				// cout << u << ' ' << v << '\n';
			}
			i++;
		}
		vector<char> appear;
		for (char c = 'A'; c <= 'Z'; c++) {
			if (g[c - 'A'].size()) appear.emplace_back(c);
		}
		int n = appear.size(), ans = INT32_MAX;
		vector<int> pos(26, -1);
		string cur_cond = "", ans_str = "";
		chaewon(n, g, appear, pos, cur_cond, ans, ans_str);
		for (char c : ans_str) cout << c << ' ';
		cout << "-> " << ans << '\n';
	}
	return 0;
}
