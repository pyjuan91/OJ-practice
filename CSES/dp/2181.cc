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
mint chaewon(int n, int m) {
	vector<mint> dp_profile(1 << n), last_profile(1 << n);
	last_profile[0] = 1;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			for (int mask = (1 << n) - 1; mask >= 0; mask--) {
				dp_profile[mask] = last_profile[mask ^ (1 << i)];
				if (i && !(mask & (1 << i)) && !(mask & (1 << (i - 1))))
					dp_profile[mask]
					  += last_profile[mask ^ (1 << (i - 1))];
			}
			swap(dp_profile, last_profile);
		}
	}
	return last_profile[0];
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	cout << chaewon(n, m);
	return 0;
}