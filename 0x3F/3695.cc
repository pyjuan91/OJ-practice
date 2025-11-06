#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
private:
	vector<int> parent_or_size;

public:
	DisjointSetUnion(size_t n) : parent_or_size(n, -1) {}

	int find(int x) {
		if (parent_or_size[x] < 0) {
			return x;
		}
		return parent_or_size[x] = find(parent_or_size[x]);
	}

	bool unite(int a, int b) {
		int par_a = find(a);
		int par_b = find(b);
		if (par_a == par_b) {
			return false;
		}

		if (parent_or_size[par_a] > parent_or_size[par_b]) {
			swap(par_a, par_b);
		}

		parent_or_size[par_a] += parent_or_size[par_b];
		parent_or_size[par_b] = par_a;

		return true;
	}

	vector<vector<int>> get_cc() {
		unordered_map<int, vector<int>> parents;
		for (int i = 0; i < parent_or_size.size(); i++) {
			int par = find(i);
			parents[par].push_back(i);
		}
		vector<vector<int>> res;
		for (const auto& [p, v] : parents) {
			res.push_back(v);
		}
		return res;
	}
};

class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
		auto dsu = DisjointSetUnion(nums.size());
		for (const auto& sw : swaps) {
			dsu.unite(sw[0], sw[1]);
		}

		vector<vector<int>> ccs = dsu.get_cc();

		long long res = 0;
		for (const auto& cc : ccs) {
			int even = 0;
			vector<int> num;
			for (const auto& x : cc) {
				if (x % 2 == 0) {
					even++;
				}
				num.push_back(nums[x]);
			}
			sort(num.rbegin(), num.rend());

			for (int i = 0; i < even; i++) {
				res += num[i];
			}
			for (int i = even; i < num.size(); i++) {
				res -= num[i];
			}
		}

		return res;
	}
};

int main() { return 0; }
