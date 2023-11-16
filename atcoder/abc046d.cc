#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int paper = 0, rock = 0;
	for (auto& c : s) {
		if (c == 'p') paper++;
		else rock++;
	}
	int quota = s.size() / 2;
    cout << quota - paper << '\n';
	return 0;
}
