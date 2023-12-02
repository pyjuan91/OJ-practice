#include <bits/stdc++.h>
using namespace std;
int chaewon(string& s1, string& s2) {
	if (s1 == s2) return 0;
	int nxt[150] = {}, in_degree[150] = {};
	int n = s1.size(), m = s2.size();
	int ans = 0;
	if (n != m) return -1;
	set<int> becomes;
	for (int i = 0; i < n; i++) {
		if (nxt[s1[i]] && nxt[s1[i]] != s2[i]) return -1;
		nxt[s1[i]] = s2[i];
		becomes.insert(s2[i]);
	}
	if (becomes.size() == 52) return -1;
	for (int i = 0; i < 150; i++) {
		if (nxt[i] && nxt[i] != i) in_degree[nxt[i]]++, ans++;
		if (nxt[i] == i) nxt[i] = 0;
	}
	int vis[150] = {};
	for (int i = 0; i < 150; i++) {
		if (nxt[i] && !vis[i]) {
			set<int> path;
			int cur = i;
			bool cycle = false;
			while (cur && !vis[cur]) {
				vis[cur] = 1;
				path.insert(cur);
				cur = nxt[cur];
				if (path.count(cur)) {
					cycle = true;
					break;
				}
			}
			if (!cycle) continue;
			path = {cur};
			while (!path.count(nxt[cur])) {
				path.insert(nxt[cur]);
				cur = nxt[cur];
			}
			bool fork = false;
			for (auto it : path) {
				if (in_degree[it] > 1) {
					fork = true;
					break;
				}
			}
			if (!fork) ans++;
		}
	}
	return ans;
}
int main() {
	int t;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		cout << chaewon(s1, s2) << endl;
	}
	return 0;
}