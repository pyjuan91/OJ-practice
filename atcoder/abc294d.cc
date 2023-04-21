#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, q, cmd, x;
	queue<int> not_been_called;
	vector<bool> come(1, false);
	queue<int> called_but_not_come;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		not_been_called.push(i);
		come.emplace_back(false);
	}
	while (q--) {
		cin >> cmd;
		if (cmd == 1) {
			auto c = not_been_called.front();
			not_been_called.pop();
			called_but_not_come.push(c);
		}
		else if (cmd == 3) {
			while (come[called_but_not_come.front()])
				called_but_not_come.pop();
			cout << called_but_not_come.front() << endl;
		}
		else {
			cin >> x;
			come[x] = true;
		}
	}
	return 0;
}