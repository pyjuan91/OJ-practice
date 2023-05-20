#include <bits/stdc++.h>
using namespace std;
bool chaewon(vector<string> &a) {
	for (int i = 0; i < (int) a.size() - 1; i++) {
		int diff_count = 0;
		for (int j = 0; j < (int) a[i].length(); j++) {
			if (a[i][j] != a[i + 1][j]) diff_count += 1;
		}
		if (diff_count != 1) return false;
	}
	return true;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &s : a) cin >> s;
	sort(a.begin(), a.end());
	do {
		if (chaewon(a)) {
			cout << "Yes\n";
			return 0;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << "No\n";
	return 0;
}