#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int candy(vector<int>& ratings) {
			int n = ratings.size(), res = 0;
			vector<int> in_degree(n, 0);
			vector<vector<int>> g(n);
			for (int i = 0; i < n; i++) {
				if (i > 0 && ratings[i] > ratings[i - 1])
					in_degree[i]++, g[i - 1].push_back(i);
				if (i < n - 1 && ratings[i] > ratings[i + 1])
					in_degree[i]++, g[i + 1].push_back(i);
			}
			queue<int> q, sc;
			for (int i = 0; i < n; i++)
				if (in_degree[i] == 0) q.push(i), sc.push(1);
			while (!q.empty()) {
				int u = q.front(), c = sc.front();
				q.pop(), sc.pop();
				res += c;
				for (int v : g[u])
					if (--in_degree[v] == 0)
						q.push(v), sc.push(c + 1);
			}
            return res;
		}
};
int32_t main() { return 0; }