#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

constexpr int kMod = 1e9 + 7;
int fast_power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % kMod;
        base = (base * base) % kMod;
        exp >>= 1;
    }
    return result;
}

int inverse(int x)
{
    return fast_power(x, kMod - 2);
}

int combination(int n, int k)
{
    if (k == 0)
        return 1;
    if (n <= 0)
        return 0;

    int numerator = 1, denominator = 1;

    for (int i = 0; i < k; i++)
    {
        numerator = numerator * ((n + k - 1 - i) % kMod) % kMod;
        denominator = denominator * ((k - i) % kMod) % kMod;
    }

    return numerator * inverse(denominator) % kMod;
}

map<int, int> factorize(int x)
{
    map<int, int> factors;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1)
    {
        factors[x]++;
    }
    return factors;
}

vector<int> get_divisors(int x)
{
    vector<int> divisors;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            divisors.push_back(i);
            if (i != x / i)
                divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int count_ways(long long n, const map<long long, int>& factors)
{
    int result = 1;

    for (const auto& [prime, exponent] : factors)
    {
        result = result * combination(n, exponent) % kMod;
    }

    return result;
}

int patty(int n, int a, int b)
{
    auto divisors_b = get_divisors(b);
    int res = 0;

    for (auto p1 : divisors_b)
    {
        if (p1 > a)
            break;

        int p2 = b / p1;
        auto factors_p1 = factorize(p1);
        auto factors_p2 = factorize(p2);
        int ways_p1 = count_ways(n, factors_p1);
        int ways_p2 = count_ways(n, factors_p2);
        res = (res + ways_p1 * ways_p2) % kMod;
    }
    return res;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n, a, b;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> n >> a >> b;
        cout << "Case #" << kase << ": ";
        cout << patty(n, a, b) << "\n";
    }
    return 0;
}
