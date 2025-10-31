#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double maxAmount(
		string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2
	) {
		queue<pair<string, double>> q;

		auto bfs = [&](const vector<vector<string>>& pairs, const vector<double>& rates) -> map<string, double> {
			size_t n = pairs.size();
			map<string, double> res;
			while (!q.empty()) {
				auto [cur, val] = q.front();
				q.pop();
				if (res.count(cur) && res[cur] >= val) {
					continue;
				}
				res[cur] = val;
				for (size_t i = 0; i < n; i++) {
					if (pairs[i][0] == cur) {
						q.push(make_pair(pairs[i][1], val * rates[i]));
					}
					if (pairs[i][1] == cur) {
						q.push(make_pair(pairs[i][0], val / rates[i]));
					}
				}
			}
			return res;
		};

		q.push(make_pair(initialCurrency, 1.0));
		map<string, double> first_day = bfs(pairs1, rates1);

		for (const auto& [cur, val] : first_day) {
			q.push(make_pair(cur, val));
		}

		map<string, double> second_day = bfs(pairs2, rates2);
		return second_day[initialCurrency];
	}
};

int main() { return 0; }
