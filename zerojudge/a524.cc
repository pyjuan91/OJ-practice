#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n;
	while (cin >> n) {
		vector<int> a(n);
		vector<vector<int>> res;
		for (int i = 0; i < n; i++) a[i] = i + 1;
		do {
			res.emplace_back(a);
		} while (next_permutation(a.begin(), a.end()));
		for (auto i = res.rbegin(); i != res.rend(); i++) {
			for (auto j : *i) cout << j;
			cout << endl;
		}
	}
	return 0;
}