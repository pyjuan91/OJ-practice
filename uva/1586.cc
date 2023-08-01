#include <bits/stdc++.h>
int32_t main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const double C = 12.01, H = 1.008, O = 16.00, N = 14.01;
	int t;
	std::string s;
	std::cin >> t;
	while (t--) {
		std::cin >> s;
		std::stringstream ss(s);
		double res = 0;
		char c;
		int n;
		while (ss >> c) {
			if (ss.peek() >= '0' && ss.peek() <= '9') ss >> n;
			else n = 1;
			if (c == 'C') res += n * C;
			else if (c == 'H') res += n * H;
			else if (c == 'O') res += n * O;
			else if (c == 'N') res += n * N;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
