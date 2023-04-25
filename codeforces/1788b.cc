#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 2 == 0) cout << n / 2 << " " << n / 2 << "\n";
		else {
			vector<int> a;
			while (n) {
				a.emplace_back(n % 10);
				n /= 10;
			}
			vector<int> b, c;
			bool type = true;
			while (!a.empty()) {
				auto ai = a.back();
				a.pop_back();
				if (ai % 2 == 0) {
					if (ai / 2 != 0 || !b.empty())
						b.emplace_back(ai / 2);
					if (ai / 2 != 0 || !c.empty())
						c.emplace_back(ai / 2);
				}
				else {
					if (type) {
						if (ai / 2 != 0 || !b.empty())
							b.emplace_back(ai / 2);
						c.emplace_back(ai / 2 + 1);
					}
					else {
						b.emplace_back(ai / 2 + 1);
						if (ai / 2 != 0 || !c.empty())
							c.emplace_back(ai / 2);
					}
					type = !type;
				}
			}
			if (b.empty()) cout << 0;
			else
				for (auto _ : b) cout << _;
			cout << " ";
			if (c.empty()) cout << 0;
			else
				for (auto _ : c) cout << _;
			cout << "\n";
		}
	}
	return 0;
}