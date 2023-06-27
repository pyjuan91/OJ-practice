#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	stack<pair<int, int>> s;
	cin >> n;
	vector<int> ans_for_each_height(n + 1, 0), height(n + 1);
	s.push(make_pair(0, 0));
	for (int i = 1; i <= n; i++) cin >> height[i];
	for (int i = 1; i <= n; i++) {
		while (s.top().first >= height[i]) s.pop();
		ans_for_each_height[i] += (i - s.top().second) * height[i];
		s.push(make_pair(height[i], i));
	}
	while (!s.empty()) s.pop();
	s.push(make_pair(0, n + 1));
	for (int i = n; i >= 1; i--) {
		while (s.top().first >= height[i]) s.pop();
		ans_for_each_height[i] += (s.top().second - i - 1) * height[i];
		s.push(make_pair(height[i], i));
	}
	cout << *max_element(
	  ans_for_each_height.begin(), ans_for_each_height.end())
		 << "\n";
	return 0;
}