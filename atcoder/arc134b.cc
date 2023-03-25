#include <bits/stdc++.h>
using namespace std;
int N;
string s;
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> N >> s;
	map<char, vector<int>> m;
	for (int i = 0; i < N; i++) m[s[i]].emplace_back(i);
	auto left = 0, right = N - 1;
	while (left < right) {
		int best_right = -1;
		for (auto& p : m) {
			if (p.first >= s[left]) break;
			while (!p.second.empty() && p.second.back() > right) {
				p.second.pop_back();
			}
			if (!p.second.empty() && p.second.back() > left) {
				best_right = p.second.back();
				p.second.pop_back();
				break;
			}
		}
		if (best_right != -1 && s[left] > s[best_right]) {
			swap(s[left], s[best_right]);
			left = left + 1;
			right = best_right - 1;
		}
		else { left += 1; }
	}
	cout << s;
	return 0;
}