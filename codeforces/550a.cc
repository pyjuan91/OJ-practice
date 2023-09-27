#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int> ab_head, ba_head;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'B' && s[i - 1] == 'A')
			ab_head.push_back(i - 1);
		else if (s[i] == 'A' && s[i - 1] == 'B')
			ba_head.push_back(i - 1);
	}
	for (auto x : ab_head) {
		auto it = lower_bound(ba_head.begin(), ba_head.end(), x);
		if (it != ba_head.end()) {
			if (*it != x + 1) {
				cout << "YES\n";
				return 0;
			}
			it++;
			if (it != ba_head.end() && *it != x + 1) {
				cout << "YES\n";
				return 0;
			}
		}
		it = lower_bound(ba_head.begin(), ba_head.end(), x);
		if (it != ba_head.begin()) {
			it--;
			if (*it != x - 1) {
				cout << "YES\n";
				return 0;
			}
			if (it != ba_head.begin()) {
				it--;
				if (*it != x - 1) {
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
    cout << "NO\n";
	return 0;
}
