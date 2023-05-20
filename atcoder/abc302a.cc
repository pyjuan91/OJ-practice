#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	cout << a / b + (a % b > 0);
	return 0;
}