#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int one_count = 0, zero_cout;
	for (auto &c : s)
		if (c == '1') one_count += 1;
	zero_cout = n - one_count;
	for (int i = 1 << one_count; i <= (1 << n) - (1 << zero_cout) + 1; i++)
		cout << i << " ";
	return 0;
}