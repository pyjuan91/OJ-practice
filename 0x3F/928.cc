#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
private:
	vector<int> parent_or_size;

public:
	DisjointSetUnion(int n) : parent_or_size(n, -1) {}

	int find(int x) {
		if (parent_or_size[x] < 0) {
			return x;
		}
		return parent_or_size[x] = find(parent_or_size[x]);
	}

	bool unite(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) {
			return false;
		}

		if (parent_or_size[pa] > parent_or_size[pb]) {
			swap(pa, pb);
		}
		parent_or_size[pa] += parent_or_size[pb];
		parent_or_size[pb] = pa;
		return true;
	}
};

class Solution {
public:
	int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
		int n = graph.size();
		auto dsu = DisjointSetUnion(n);
		vector<bool> is_init(n);
		for (const auto& x : initial) {
			is_init[x] = true;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (graph[i][j] and !is_init[i] and !is_init[j]) {
					dsu.unite(i, j);
				}
			}
		}

		vector<int> p(n);
		vector<int> cc_size(n);

		for (int i = 0; i < n; i++) {
			if (is_init[i]) {
				continue;
			}
			int cur_p = dsu.find(i);
			cc_size[cur_p]++;
			p[i] = cur_p;
		}

		vector<set<int>> cc_neighbors(n);
		for (const auto& x : initial) {
			for (int i = 0; i < n; i++) {
				if (!is_init[i] and graph[x][i]) {
					int root = dsu.find(i);
					cc_neighbors[root].insert(x);
				}
			}
		}

		int res_save = 0, res_id = *min_element(initial.begin(), initial.end());

		for (const auto& x : initial) {
			int cur_save = 0;
			set<int> visited_cc;

			for (int i = 0; i < n; i++) {
				if (!is_init[i] and graph[x][i]) {
					int root = dsu.find(i);
					if (visited_cc.count(root)) {
						continue;
					}
					visited_cc.insert(root);
					if (cc_neighbors[root].size() == 1) {
						cur_save += cc_size[root];
					}
				}
			}

			if (cur_save > res_save or cur_save == res_save and x < res_id) {
				res_id = x;
				res_save = cur_save;
			}
		}

		return res_id;
	}
};

int main() { return 0; }
