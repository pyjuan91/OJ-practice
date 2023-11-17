#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	while (cin >> n && n) {
		int x = 2 * n - 1;
		vector<int> a(x), res;
		for (auto& i : a) cin >> i;
		function<bool(int, int, int)> chaewon
		  = [&](int id, int sum, int sel) {
			if (id == x) return sel == n && sum % n == 0;
            if (sel == n) return sum % n == 0;
			if (x - id < n - sel) return false;
			if (chaewon(id + 1, sum + a[id], sel + 1)) {
				res.push_back(a[id]);
				return true;
			}
			if (chaewon(id + 1, sum, sel)) return true;
			return false;
		};
		if (chaewon(0, 0, 0)) {
			cout << "Yes\n";
			for (int i = 0; i < n; i++)
				cout << res[i] << " \n"[i == n - 1];
		}
		else cout << "No\n";
	}
	return 0;
}
