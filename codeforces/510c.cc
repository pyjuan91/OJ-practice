#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> a(n);
	vector<vector<int>> one_dir(26, vector<int>(26, -1));
	vector<int> in_degree(26, 0), topo_res;
	for (auto& x : a) cin >> x;
	if (n == 1) {
		for (int i = 0; i < 26; i++) cout << char('a' + i);
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int lena = a[i - 1].length(), lenb = a[i].length();
		bool finish_compare = false;
		for (int j = 0; j < min(lena, lenb); j++) {
			if (a[i - 1][j] != a[i][j]) {
				int smaller_char = a[i - 1][j] - 'a',
					bigger_char = a[i][j] - 'a';
				if (one_dir[smaller_char][bigger_char] == -1) {
					one_dir[smaller_char][bigger_char] = 1;
					one_dir[bigger_char][smaller_char] = 0;
					in_degree[bigger_char]++;
				}
				else if (one_dir[smaller_char][bigger_char] == 0) {
					cout << "Impossible";
					return 0;
				}
                finish_compare = true;
				break;
			}
		}
		if (!finish_compare && lena > lenb) {
			cout << "Impossible";
			return 0;
		}
	}
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (in_degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo_res.push_back(u);
		for (int v = 0; v < 26; v++) {
			if (one_dir[u][v] == 1) {
				in_degree[v]--;
				if (in_degree[v] == 0) q.push(v);
			}
		}
	}
	if (topo_res.size() != 26) {
		cout << "Impossible";
		return 0;
	}
	for (auto x : topo_res) cout << char('a' + x);
	return 0;
}