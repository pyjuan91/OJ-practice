#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		string rev = "";
		vector<int> rev_id;
		int left = 0, rev_right = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				if (rev_right) {
					rev_right--;
					rev += '(';
					rev_id.push_back(i);
				}
				else left++;
			}
			else if (s[i] == ')') {
				if (left) left--;
				else {
					rev_right++;
					rev += ')';
					rev_id.push_back(i);
				}
			}
		}
		// for(auto c : rev) cout << c << " ";
		// cout << '\n';
		auto regular = [&](string& s) {
			int left = 0;
			for (auto c : s) {
				if (c == '(') left++;
				else if (left) left--;
				else return false;
			}
			return left == 0;
		};
		reverse(rev.begin(), rev.end());
		if (left != 0 || !regular(rev)) {
			cout << "-1\n";
			continue;
		}
		if (rev_id.empty() || rev_id.size() == n) {
			cout << "1\n";
			for (int i = 0; i < n; i++) cout << "1 ";
			cout << '\n';
			continue;
		}
		cout << "2\n";
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (index < rev_id.size() && i == rev_id[index]) {
				cout << "2 ";
				index++;
			}
			else cout << "1 ";
		}
		cout << '\n';
	}
	return 0;
}
