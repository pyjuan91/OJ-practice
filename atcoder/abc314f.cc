#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
struct dsu {
	public:
		dsu()
		  : _n(0) {}
		explicit dsu(int n)
		  : _n(n)
		  , parent_or_size(n) {
			for (int i = 0; i < n; i++) parent_or_size[i] = i;
		}

		void merge(int a, int b) {
			int x = leader(a), y = leader(b);
			parent_or_size[x] = y;
		}

		bool same(int a, int b) {
			return leader(a) == leader(b);
		}

		int leader(int a) {
			if (parent_or_size[a] == a) return a;
			return parent_or_size[a] = leader(parent_or_size[a]);
		}

	private:
		int _n;
		// root node: -1 * component size
		// otherwise: parent
		std::vector<int> parent_or_size;
};

void dfs(int n, int cur, mint accu, auto &child, auto &res, auto &rc) {
	if (cur <= n) {
		res[cur] = accu;
		return;
	}
	for (auto c : child[cur])
		dfs(n, c, accu + rc[c], child, res, rc);
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, extra_hash, a, b;
	cin >> n;
	auto d = dsu(2 * n + 5);
	extra_hash = n;
	vector<vector<int>> child(2 * n + 5);
	vector<mint> sz(2 * n + 5, 1), rc(2 * n + 5), res(n + 1, 0);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		a = d.leader(a);
		b = d.leader(b);
		rc[a] = sz[a] / (sz[a] + sz[b]);
		rc[b] = sz[b] / (sz[a] + sz[b]);
		extra_hash += 1;
		d.merge(a, extra_hash);
		d.merge(b, extra_hash);
		child[extra_hash].push_back(a);
		child[extra_hash].push_back(b);
		sz[extra_hash] = sz[a] + sz[b];
	}
	dfs(n, extra_hash, 0, child, res, rc);
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	return 0;
}