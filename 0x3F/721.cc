#include <bits/stdc++.h>
using namespace std;

constexpr int kMax = 100005;
class DisjointUnionSet {
private:
	vector<int> parent_or_size;

public:
	DisjointUnionSet() : parent_or_size(kMax, -1) {}

	int find(int x) {
		if (parent_or_size[x] < 0) {
			return x;
		}
		return parent_or_size[x] = find(parent_or_size[x]);
	}

	bool unite(int a, int b) {
		int parent_a = find(a);
		int parent_b = find(b);

		if (parent_a == parent_b) {
			return false;
		}

		if (parent_or_size[parent_a] > parent_or_size[parent_b]) {
			swap(parent_a, parent_b);
		}

		parent_or_size[parent_a] += parent_or_size[parent_b];
		parent_or_size[parent_b] = parent_a;

		return true;
	}

	int get_size(int x) {
		int parent_x = find(x);
		return -parent_or_size[parent_x];
	}
};

class Solution {
private:
	unordered_map<string, int> gen_hash_table(const vector<vector<string>>& v) {
		int idx = 1;
		unordered_map<string, int> res;
		for (const auto& vv : v) {
			for (const auto& vvv : vv) {
				if (!res.count(vvv)) {
					res[vvv] = idx++;
				}
			}
		}
		return res;
	}

public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		unordered_map<string, int> hashed_map = gen_hash_table(accounts);
		unordered_map<int, string> reversed_hash;
		for (const auto& p : hashed_map) {
			reversed_hash[p.second] = p.first;
		}

		auto dsu = DisjointUnionSet();
		unordered_map<int, int> email_name;
		for (const auto& account : accounts) {
			for (size_t i = 1; i < account.size(); i++) {
				email_name[hashed_map[account[i]]] = hashed_map[account[0]];
				if (i > 1) {
					dsu.unite(hashed_map[account[i]], hashed_map[account[1]]);
				}
			}
		}

		unordered_map<int, vector<int>> ccs;
		for (const auto& p : reversed_hash) {
			if (email_name.count(p.first)) {
				ccs[dsu.find(p.first)].push_back(p.first);
			}
		}

		vector<vector<string>> res;
		for (const auto& p : ccs) {
			vector<string> v;
			for (const auto& x : p.second) {
				v.push_back(reversed_hash[x]);
			}
			sort(v.begin(), v.end());
			v.insert(v.begin(), reversed_hash[email_name[p.second[0]]]);
			res.push_back(v);
		}

		return res;
	}
};

int main() { return 0; }
