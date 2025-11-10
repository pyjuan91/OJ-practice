#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		vector<bool> is_known(n, false);
		is_known[0] = is_known[firstPerson] = true;

		sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) { return a[2] < b[2]; });
		int cur_time = meetings[0][2];
		for (int i = 0; i < meetings.size();) {
			unordered_map<int, int> parent_or_size;
			auto find = [&](this auto& self, int x) -> int {
				if (!parent_or_size.count(x)) {
					parent_or_size[x] = -1;
				}
				if (parent_or_size[x] < 0) {
					return x;
				}
				return parent_or_size[x] = self(parent_or_size[x]);
			};
			auto unite = [&](int a, int b) -> void {
				int pa = find(a);
				int pb = find(b);
				if (pa == pb) {
					return;
				}
				if (parent_or_size[pa] > parent_or_size[pb]) {
					swap(pa, pb);
				}
				parent_or_size[pa] += parent_or_size[pb];
				parent_or_size[pb] = pa;
			};
			unordered_set<int> nodes;
			while (i < meetings.size() && meetings[i][2] == cur_time) {
				int u = meetings[i][0], v = meetings[i][1];
				unite(u, v);
				nodes.insert(u);
				nodes.insert(v);
				i++;
			}
			if (i < meetings.size()) {
				cur_time = meetings[i][2];
			}
			unordered_map<int, vector<int>> ccs;
			for (const auto& node : nodes) {
				int pnode = find(node);
				ccs[pnode].push_back(node);
			}
			for (const auto& [p, cc] : ccs) {
				bool does_sb_know = false;
				for (const auto& x : cc) {
					if (is_known[x]) {
						does_sb_know = true;
						break;
					}
				}
				if (does_sb_know) {
					for (const auto& x : cc) {
						is_known[x] = true;
					}
				}
			}
		}

		vector<int> res;
		for (int i = 0; i < n; i++) {
			if (is_known[i]) {
				res.push_back(i);
			}
		}

		return res;
	}
};

int main() { return 0; }
