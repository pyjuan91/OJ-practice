#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	public:
		vector<int> parent;
		int n;
		DisjointSet(int _n) {
			n = _n;
			parent.resize(n + 1);
			for (int i = 0; i <= n; i++) parent[i] = i;
		}
		int find_root(int a) {
			if (parent[a] == a) return a;
			return parent[a] = find_root(parent[a]);
		}
		bool is_same(int a, int b) {
			return find_root(a) == find_root(b);
		}
		void unite(int a, int b) {
			int a_root = find_root(a), b_root = find_root(b);
			parent[a_root] = b_root;
		}
};
class Solution {
	public:
		int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
			sort(edges.begin(), edges.end(), [&](auto& a, auto& b) {
				return a[0] > b[0];
			});
			int res = 0;
			auto alice = DisjointSet(n);
			auto bob = DisjointSet(n);
			for (auto edge : edges) {
				if (edge[0] == 3 || edge[0] == 1) {
					if (alice.is_same(edge[1], edge[2]))
						res += 1;
					else alice.unite(edge[1], edge[2]);
				}
				if (edge[0] == 3 || edge[0] == 2) {
					if (bob.is_same(edge[1], edge[2]) && edge[0] == 2)res += 1;
					else bob.unite(edge[1], edge[2]);
				}
			}

			int alice_root = alice.find_root(1),
				bob_root = bob.find_root(1);
			for (int i = 2; i <= n; i++) {
				if (alice.find_root(i) != alice_root || bob.find_root(i) != bob_root)
					return -1;
			}
			return res;
		}
};
int main() { return 0; }