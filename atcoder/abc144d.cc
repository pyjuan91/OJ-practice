#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	double a, b, c;
	cin >> a >> b >> c;
	double cap = a * a * b;
	auto equal_to = [&](double a, double b) -> bool {
		return fabs(a - b) < numeric_limits<double>::epsilon();
	};
	auto less_than_or_equal_to = [&](double a, double b) -> bool {
		return a < b || equal_to(a, b);
	};
	if (less_than_or_equal_to(c, cap / 2)) {
		// na * b * a / 2 = c
		double na = 2 * c / (b * a);
		double l = sqrt(na * na + b * b);
		cout << fixed << setprecision(10)
			 << acos(na / l) * 180 / M_PI << '\n';
	}
	else {
		// nb * a * a / 2 = cap - c
		double nb = 2 * (cap - c) / (a * a);
		double l = sqrt(nb * nb + a * a);
		cout << fixed << setprecision(10)
			 << 90.0 - acos(nb / l) * 180 / M_PI << '\n';
	}
	return 0;
}
