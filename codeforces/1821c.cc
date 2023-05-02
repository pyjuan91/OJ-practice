#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		int res = 1e9;
		for (char c = 'a'; c <= 'z'; c++) {
			int continuous = 0, this_sol = 0;
			for (int i = 0; i < int(str.length()); i++) {
				if (str[i] != c) continuous += 1;
				else {
					if (continuous == 0) continue;
					this_sol = max(this_sol, int(log2(continuous)) + 1);
					continuous = 0;
				}
			}
			if (continuous != 0)
				this_sol = max(this_sol, int(log2(continuous)) + 1);
			res = min(res, this_sol);
		}
		cout << res << "\n";
	}
	return 0;
}