#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<int> a(k + 1);
		for (int i = 1; i <= k; i++) cin >> a[i];
		int max_capcity = n * m - 3, cur_occupation = 0,
			last_deck_top = k + 1;
		priority_queue<int> pending;
		for (int i = 1; i <= k; i++) {
			if (a[i] == last_deck_top - 1) {
				last_deck_top -= 1;
				while (!pending.empty()
					   && pending.top() == last_deck_top - 1) {
					last_deck_top -= 1;
					pending.pop();
					cur_occupation -= 1;
				}
			}
			else {
				cur_occupation += 1;
				pending.push(a[i]);
				if (cur_occupation == max_capcity) {
					cout << "TIDAK\n";
					goto chaewon;
				}
			}
		}
		cout << "YA\n";
	chaewon:;
	}
	return 0;
}