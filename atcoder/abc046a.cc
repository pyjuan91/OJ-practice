#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x;
	set<int> s;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		s.insert(x);
	}
    cout << s.size() << '\n';
	return 0;
}
