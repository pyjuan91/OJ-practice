#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int findChampion(int n, vector<vector<int>>& edges) {
			vector<int> in_indegree(n), champion;
			for (auto& e : edges) { in_indegree[e[1]]++; }
			for (int i = 0; i < n; i++) {
				if (in_indegree[i] == 0) champion.push_back(i);
			}
			return champion.size() == 1 ? champion[0] : -1;
		}
};
int main() {
	Solution s;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(2));
	for (int i = 0; i < m; i++) {
		cin >> edges[i][0] >> edges[i][1];
	}
	cout << s.findChampion(n, edges) << endl;
	return 0;
}