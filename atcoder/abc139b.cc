#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << (b - 1) / (a - 1) + ((b - 1) % (a - 1) > 0);
	return 0;
}