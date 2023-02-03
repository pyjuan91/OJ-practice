#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n;
	string str;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		vector<bool> appear(26, false);
		vector<bool> appear_two(26, false);
		vector<int> front(n);
		vector<int> end(n);
		appear[str[0] - 'a'] = true;
		front[0] = 1;
		appear_two[str[n - 1] - 'a'] = true;
		end[n - 1] = 1;
		for (int i = 1; i < n; i++) {
			if (!appear[str[i] - 'a']) {
				appear[str[i] - 'a'] = true;
				front[i] = front[i - 1] + 1;
			}
			else front[i] = front[i - 1];

			if (!appear_two[str[n - i - 1] - 'a']) {
				appear_two[str[n - i - 1] - 'a'] = true;
				end[n - i - 1] = end[n - i] + 1;
			}
			else end[n - i - 1] = end[n - i];
		}
		int res = 0;
		for (int i = 0; i < n - 1; i++) {
			res = max(res, front[i] + end[i + 1]);
		}
		cout << res << "\n";
	}
	return 0;
}