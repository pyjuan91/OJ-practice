#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		tree[x].emplace_back(i);
		tree[i].emplace_back(x);
	}
	vector<bool> vist(n + 1, false);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!vist[i]) {
			res += 1;
			queue<int> q;
			q.push(i);
			vist[i] = true;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (auto child : tree[cur]) {
					if (vist[child] == false) {
						vist[child] = true;
						q.push(child);
					}
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}