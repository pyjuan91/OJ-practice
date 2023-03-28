#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> route(n + 1);
	vector<int> indegree(n + 1, 0);
	while (m--) {
		cin >> x >> y;
		route[x].emplace_back(y);
		indegree[y] += 1;
	}
	int cnt = 0, head;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) {
			cnt += 1;
			head = i;
		}
	if (cnt != 1) {
		cout << "No";
		return 0;
	}
	vector<int> ans;
	int cur = head;
	for (;;) {
		ans.emplace_back(cur);
		cnt = 0;
		for (auto child : route[cur]) {
			indegree[child] -= 1;
			if (indegree[child] == 0) {
				cnt += 1;
				head = child;
			}
		}
		if (cnt == 0 && ans.size() == n) break;
		if (cnt != 1) {
			cout << "No";
			return 0;
		}
		cur = head;
	}
	vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) res[ans[i - 1]] = i;
	cout << "Yes\n" << res[1];
	for (int i = 2; i <= n; i++) cout << " " << res[i];
	return 0;
}