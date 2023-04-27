#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> a(k + 1), b(k + 1);
		string res = "abc";
		char for_generating_palin = 'd';
		auto prev_a = 3;
		auto prev_b = 3;
		auto not_palin_index = 0;

		for (int i = 1; i <= k; i++) cin >> a[i];
		for (int i = 1; i <= k; i++) cin >> b[i];

		for (int i = 1; i <= k; i++) {
			if (b[i] - b[i - 1] > a[i] - a[i - 1]) {
				cout << "NO\n";
				goto chaewon;
			}
		}

		for (int i = 1; i <= k; i++) {
			// add not palin part
			// not palin part = extra a - extra b
			// = a - prev_a - (b - prev_b)
			for (int j = 0; j < a[i] - prev_a - (b[i] - prev_b); j++) {
				res.push_back(res[not_palin_index]);
				not_palin_index = (not_palin_index + 1) % 3;
			}
			// add palin part
			// for_gen_palin from d to z
			// no exceed because k <= 20
			for (int j = 0; j < b[i] - prev_b; j++)
				res.push_back(for_generating_palin);

			for_generating_palin = (char) (for_generating_palin + 1);
			prev_a = a[i];
			prev_b = b[i];
		}
		cout << "YES\n" << res << "\n";
	chaewon: {}
	}
	return 0;
}