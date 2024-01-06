#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
			// hash the start time and end time
			map<int, int> hash;
			for (auto x : startTime) hash[x];
			for (auto x : endTime) hash[x];
			int idx = 0;
			for (auto& x : hash) x.second = idx++;

			// sort the jobs by end time
			int n = startTime.size();
			vector<tuple<int, int, int>> jobs;
			for (int i = 0; i < n; i++) {
				jobs.push_back(make_tuple(
				  hash[endTime[i]], hash[startTime[i]], profit[i]));
			}
			sort(jobs.begin(), jobs.end());

			// dp on max segment tree
			const int mx = hash.size() + 1;
			vector<int> seg(2 * mx, 0);
			auto update = [&](int p, int v) {
				p += mx;
				for (seg[p] = max(seg[p], v); p > 1; p >>= 1)
					seg[p >> 1] = max(seg[p], seg[p ^ 1]);
			};
			auto query = [&](int l, int r) {
				int res = 0;
				for (l += mx, r += mx; l < r; l >>= 1, r >>= 1) {
					if (l & 1) res = max(res, seg[l++]);
					if (r & 1) res = max(res, seg[--r]);
				}
				return res;
			};

			for (int i = 0; i < n; i++) {
				auto [e, s, p] = jobs[i];
				int prev = query(0, s + 1);
				update(e, prev + p);
			}
			return query(0, mx - 1);
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> startTime(n), endTime(n), profit(n);
	for (int i = 0; i < n; i++) cin >> startTime[i];
	for (int i = 0; i < n; i++) cin >> endTime[i];
	for (int i = 0; i < n; i++) cin >> profit[i];
	cout << s.jobScheduling(startTime, endTime, profit) << endl;
	return 0;
}