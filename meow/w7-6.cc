#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
typedef long long ll;
class Factorial {
public:
    vector<ll> factorial;
    vector<ll> inverseFactorial;
    ll mod;
    ll ModularBinaryExponentiation(ll base, ll exponent)
    {
        if (exponent == 0)
            return 1;
        ll result = ModularBinaryExponentiation(base, exponent / 2);
        if (exponent % 2 == 1)
            return (((result * result) % mod) * base) % mod;
        return (result * result) % mod;
    }
    Factorial(ll n, ll _mod)
    {
        factorial.resize(n + 1);
        inverseFactorial.resize(n + 1);
        mod = _mod;
        factorial[0] = 1;
        inverseFactorial[0] = 1;

        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
            inverseFactorial[i]
                = ModularBinaryExponentiation(factorial[i], mod - 2);
        }
    }
    ll GetFacOf(ll n)
    {
        return factorial[n];
    }
    ll GetInvOf(ll n)
    {
        return inverseFactorial[n];
    }
    ll GetC(ll a, ll b)
    {
        return (((GetFacOf(a) * GetInvOf(a - b)) % mod) * GetInvOf(b)) % mod;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Factorial f(1e6, 1e9 + 7);
    ll n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << f.GetC(a, b) << endl;
    }
    return 0;
}