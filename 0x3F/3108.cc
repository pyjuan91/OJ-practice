#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
private:
	int _n;
	vector<int> _parent_or_size;

public:
	DisjointSetUnion(int n) {
		_n = n;
		_parent_or_size.assign(n, -1);
	}

	int find(int x) {
		if (_parent_or_size[x] < 0) {
			return x;
		}
		return _parent_or_size[x] = find(_parent_or_size[x]);
	}

	bool unite(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) {
			return false;
		}
		if (_parent_or_size[pa] > _parent_or_size[pb]) {
			swap(pa, pb);
		}
		_parent_or_size[pa] += _parent_or_size[pb];
		_parent_or_size[pb] = pa;
		return true;
	}

	bool is_same(int a, int b) { return find(a) == find(b); }
};

class Solution {
public:
	vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
		auto dsu = DisjointSetUnion(n);
		for (const auto& edge : edges) {
			int u = edge[0], v = edge[1], w = edge[2];
			dsu.unite(u, v);
		}

		unordered_map<int, int> ccs_walk;
		for (const auto& edge : edges) {
			int u = edge[0], w = edge[2];
			int cc = dsu.find(u);
			if (ccs_walk.count(cc)) {
				ccs_walk[cc] = ccs_walk[cc] & w;
			} else {
				ccs_walk[cc] = w;
			}
		}

		vector<int> res;
		for (const auto& q : query) {
			int u = q[0], v = q[1];
			if (dsu.is_same(u, v)) {
				res.push_back(ccs_walk[dsu.find(u)]);
			} else {
				res.push_back(-1);
			}
		}

		return res;
	}
};

int main() { return 0; }
