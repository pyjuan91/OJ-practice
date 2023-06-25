#include <bits/stdc++.h>
using namespace std;
void chaewon(int& n, string& s) {
	vector<int> counter(26, 0);
	for (auto& c : s) counter[c - 'a']++;
	vector<int> most_freq;
	for (int i = 0; i < 26; i++) most_freq.emplace_back(i);
	sort(most_freq.begin(), most_freq.end(), [&](int a, int b) {
		return counter[a] > counter[b];
	});
	int best_choice_same = 0, best_choice_distinct = 0;
	for (int i = 1; i <= 26; i++) {
		if (n % i != 0) continue;
		int cur_same = 0;
		for (int j = 0; j < i; j++)
			cur_same += min(counter[most_freq[j]], n / i);
		if (cur_same > best_choice_same) {
			best_choice_same = cur_same;
			best_choice_distinct = i;
		}
	}
	cout << n - best_choice_same << '\n';
	string ans = "";
	vector<int> char_pool(26, 0);
	for (int i = 0; i < best_choice_distinct; i++)
		char_pool[most_freq[i]] = n / best_choice_distinct;
	for (auto& c : s) {
		if (char_pool[c - 'a']) {
			ans.push_back(c);
			char_pool[c - 'a']--;
		}
		else ans.push_back('?');
	}
	for (auto& c : ans) {
		if (c == '?') {
			for (int i = 0; i < 26; i++) {
				if (char_pool[i]) {
					c = 'a' + i;
					char_pool[i]--;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		chaewon(n, s);
	}
	return 0;
}