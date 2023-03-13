// #include <bits/stdc++.h>
// using namespace std;
// int chaewon(
//   vector<vector<int>>& edge, int cur,
//   vector<bool>& used, vector<int>& dp) {
// 	int longest_child = 0;
// 	if (dp[cur]) return dp[cur];
// 	for (auto e : edge[cur]) {
// 		if (used[e]) continue;
// 		used[e] = true;
// 		longest_child = max(
// 		  longest_child, chaewon(edge, e, used, dp));
// 		used[e] = false;
// 	}
// 	return dp[cur] = longest_child + 1;
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie();
// 	int n, m, a, b, res = 0;
// 	cin >> n >> m;
// 	vector<vector<int>> edge(n + 1);
// 	vector<int> dp(n + 1, 0);
// 	vector<bool> used(n + 1, false);
// 	for (int i = 0; i < m; i++) {
// 		cin >> a >> b;
// 		edge[a].emplace_back(b);
// 	}
// 	for (int i = 1; i <= n; i++) {
// 		if (dp[i]) continue;
// 		used[i] = true;
// 		res = max(res, chaewon(edge, i, used, dp));
// 		used[i] = false;
// 	}
// 	cout << res - 1;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, a, b, cur, res = 0;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1);
	vector<int> indegree(n + 1, 0), dp(n + 1, 0);
	queue<int> q;
	while (m--) {
		cin >> a >> b;
		edge[a].emplace_back(b);
		indegree[b] += 1;
	}
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		res = max(res, dp[cur]);
		for (auto e : edge[cur]) {
			dp[e] = max(dp[e], dp[cur] + 1);
			indegree[e] -= 1;
			if (indegree[e] == 0) q.push(e);
		}
	}
	cout << res;
	return 0;
}