#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int L, Q, c, x;
	cin >> L >> Q;
	set<int> s;
	s.insert(0);
	s.insert(L);
	while (Q--) {
		cin >> c >> x;
		if (c == 1) s.insert(x);
		else {
			auto prev = s.lower_bound(x);
			prev--;
			auto next = s.upper_bound(x);
			cout << *next - *prev << "\n";
		}
	}
	return 0;
}