#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
template<const int32_t MOD> struct modint {
		int32_t value;
		modint() = default;
		modint(int32_t value_)
		  : value(value_) {}
		inline modint<MOD> operator+(modint<MOD> other) const {
			int32_t c = this->value + other.value;
			return modint<MOD>(c >= MOD ? c - MOD : c);
		}
		inline modint<MOD> operator-(modint<MOD> other) const {
			int32_t c = this->value - other.value;
			return modint<MOD>(c < 0 ? c + MOD : c);
		}
		inline modint<MOD> operator*(modint<MOD> other) const {
			int32_t c = (int64_t) this->value * other.value % MOD;
			return modint<MOD>(c < 0 ? c + MOD : c);
		}
		inline modint<MOD> &operator+=(modint<MOD> other) {
			this->value += other.value;
			if (this->value >= MOD) this->value -= MOD;
			return *this;
		}
		inline modint<MOD> &operator-=(modint<MOD> other) {
			this->value -= other.value;
			if (this->value < 0) this->value += MOD;
			return *this;
		}
		inline modint<MOD> &operator*=(modint<MOD> other) {
			this->value = (int64_t) this->value * other.value % MOD;
			if (this->value < 0) this->value += MOD;
			return *this;
		}
		inline modint<MOD> operator-() const {
			return modint<MOD>(this->value ? MOD - this->value : 0);
		}
		modint<MOD> pow(uint64_t k) const {
			modint<MOD> x = *this, y = 1;
			for (; k; k >>= 1) {
				if (k & 1) y *= x;
				x *= x;
			}
			return y;
		}
		modint<MOD> inv() const {
			return pow(MOD - 2);
		} // MOD must be a prime
		inline modint<MOD> operator/(modint<MOD> other) const {
			return *this * other.inv();
		}
		inline modint<MOD> operator/=(modint<MOD> other) {
			return *this *= other.inv();
		}
		inline bool operator==(modint<MOD> other) const {
			return value == other.value;
		}
		inline bool operator!=(modint<MOD> other) const {
			return value != other.value;
		}
		inline bool operator<(modint<MOD> other) const {
			return value < other.value;
		}
		inline bool operator>(modint<MOD> other) const {
			return value > other.value;
		}
};
template<int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) {
	return modint<MOD>(value) * n;
}
template<int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) {
	return modint<MOD>(value % MOD) * n;
}
template<int32_t MOD>
istream &operator>>(istream &in, modint<MOD> &n) {
	return in >> n.value;
}
template<int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) {
	return out << n.value;
}

using mint = modint<mod>;
const int maxn = 1e6 + 5;
mint dp[maxn][2] = {};
void init() {
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < maxn; i++) {
		dp[i][0] = dp[i - 1][0] * 4 + dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0];
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	init();
	while (t--) {
		cin >> n;
		cout << dp[n][0] + dp[n][1] << endl;
	}
	return 0;
}