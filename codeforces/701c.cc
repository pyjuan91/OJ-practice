#include <bits/stdc++.h>
using namespace std;
bool chaewon(vector<int>& a, vector<bool>& b) {
	for (int i = 0; i < 52; i++) {
		if ((b[i] && a[i] > 0) || (!b[i] && a[i] == 0))
			continue;
		return false;
	}
	return true;
}
int get_index(char& c) {
	if (c >= 'a' && c <= 'z') return (int) (c - 'a');
	return (int) (26 + c - 'A');
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 1e9, left = 0;
	string s;
	cin >> n >> s;
	vector<bool> a(52, 0);
	for (auto& c : s) a[get_index(c)] = true;
	vector<int> current(52, 0);
	for (int i = 0; i < n; i++) {
		current[get_index(s[i])] += 1;
		if (chaewon(current, a)) {
			for (;;) {
				if (left >= i) break;
				current[get_index(s[left])] -= 1;
				if (!chaewon(current, a)) {
					current[get_index(s[left])] += 1;
					break;
				}
				left += 1;
			}
			res = min(res, i - left + 1);
		}
	}
	cout << res << "\n";
	return 0;
}