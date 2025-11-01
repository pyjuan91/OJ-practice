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
		return find(parent_or_size[x]);
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return false;
		}

		if (parent_or_size[x] > parent_or_size[y]) {
			swap(x, y);
		}
		parent_or_size[x] += parent_or_size[y];
		parent_or_size[y] = x;

		return true;
	}

	int size(int x) { return -parent_or_size[find(x)]; }
};

class Solution {
public:
	int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
		int n = graph.size();
		auto dsu = DisjointSetUnion(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j]) {
					dsu.unite(i, j);
				}
			}
		}

		unordered_map<int, int> comp_init_cnt;
		for (int node : initial) {
			comp_init_cnt[dsu.find(node)]++;
		}

		int best_node = *min_element(initial.begin(), initial.end());
		int max_saved = 0;

		for (int node : initial) {
			int comp = dsu.find(node);
			if (comp_init_cnt[comp] == 1) {
				int saved = dsu.size(comp);
				if (saved > max_saved or saved == max_saved and node < best_node) {
					best_node = node;
					max_saved = saved;
				}
			}
		}

		return best_node;
	}
};

int main() { return 0; }
