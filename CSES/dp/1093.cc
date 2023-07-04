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
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, target;
	cin >> n;
	target = n * (n + 1) / 2;
	if (target & 1) {
		cout << 0;
		return 0;
	}
	target /= 2;
	vector<mint> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int gen_sum = target; gen_sum >= i; gen_sum--)
			dp[gen_sum] += dp[gen_sum - i];
	cout << dp[target] / 2;
	return 0;
}