#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, d, head, m, left_node, right_node;
	cin >> n;
	vector<int> left(n + 1, 0), right(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		cin >> x >> d;
		if (d == 0) {
			left[i] = left[x];
            right[left[x]] = i;
			left[x] = i;
			right[i] = x;
		}
		else {
			right[i] = right[x];
            left[right[x]] = i;
			right[x] = i;
			left[i] = x;
		}
	}
	cin >> m;
	while (m--) {
		cin >> x;
		left_node = left[x];
		right_node = right[x];
		left[x] = right[x] = -1;
		if (right_node > 0) left[right_node] = left_node;
		if (left_node > 0) right[left_node] = right_node;
	}
	for (int i = 1; i <= n; i++)
		if (left[i] == 0) head = i;
	while (head) {
		cout << head << " ";
		head = right[head];
	}
	return 0;
}
