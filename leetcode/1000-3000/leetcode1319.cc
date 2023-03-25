#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	public:
		int n;
		vector<int> parent;
		DisjointSet(int _n) {
			n = _n;
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}
		int findRoot(int a) {
			if (parent[a] == a) return a;
			return parent[a] = findRoot(parent[a]);
		}
		bool isSame(int a, int b) {
			return findRoot(a) == findRoot(b);
		}
		void unite(int a, int b) {
			parent[findRoot(a)] = findRoot(b);
		}
};
class Solution {
	public:
		int makeConnected(int n, vector<vector<int>>& connections) {
			if (connections.size() < n - 1) return -1;
			auto djs = DisjointSet(n);
			for (auto p : connections) djs.unite(p[0], p[1]);
			set<int> cc;
			for (int i = 0; i < n; i++)
				cc.insert(djs.findRoot(i));
			return cc.size() - 1;
		}
};
int main() { return 0; }