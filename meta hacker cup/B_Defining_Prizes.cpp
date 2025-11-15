#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;

using namespace std;

int patty() {
	int n, m;
	cin >> n >> m;

	map<int, int> score_counts;
	for (int i = 0; i < n; ++i) {
		int score;
		cin >> score;
		score_counts[score]++;
	}

	vector<pair<int, int>> groups;
	for (const auto& [score, count] : score_counts) {
		groups.push_back({score, count});
	}

	int P = groups.size();

	vector<int> B(m);
	for (int& b : B) {
		cin >> b;
	}

	sort(B.rbegin(), B.rend());

	vector<int> suff_people(P + 1, 0);
	for (int i = P - 1; i >= 0; --i) {
		suff_people[i] = suff_people[i + 1] + groups[i].second;
	}
	auto check = [&](int p) -> bool {
		if (p == 0) {
			return true;
		}
		if (p > m) {
			return false;
		}

		vector<int> req(p + 1, 0);
		int current_sum = 0;
		for (int i = p; i >= 1; --i) {
			current_sum += groups[P - p + i - 1].second;
			req[i] = current_sum;
		}

		long long quota = 0;
		for (int i = p + 1; i <= m; ++i) {
			quota += B[i - 1];
		}

		long long total_deficit = 0;
		long long total_surplus = 0;

		for (int i = 1; i <= p; ++i) {

			if (B[i - 1] < req[i]) {

				total_deficit += (req[i] - B[i - 1]);
			} else {

				total_surplus += (B[i - 1] - req[i]);
			}
		}

		return (total_surplus + quota >= total_deficit);
	};

	int left = 0, right = P;
	int max_people = 0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check(mid)) {

			max_people = suff_people[P - mid];
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return max_people;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": " << patty() << "\n";
	}
	return 0;
}
