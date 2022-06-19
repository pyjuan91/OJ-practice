#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 2000000;
int prime[maxn];
vector<int> primevector;
void catchprime()
{
    for (int i = 0; i < maxn; i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    int sqrt_maxn = sqrt(maxn);
    for (int i = 2; i <= sqrt_maxn; i++)
    {
        if (prime[i] == 1)
        {
            for (int k = (maxn - 1) / i, j = i * k; k >= i; k--, j -= i)
            {
                if (prime[k] == 1)
                {
                    prime[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < maxn; i++)
        if (prime[i] == 1)
            primevector.push_back(i);
}
int main(void)
{
    catchprime();
    int n;
    cin >> n;
    int fac = 2;
    int first = 1;
    int cnt = 0;
    while (n > 1 && fac <= n)
    {
        int d = 0;
        while (n % fac == 0 && n > 1)
        {
            d++;
            n /= fac;
        }
        if (!first)
            cout << " * ";
        if (d)
        {
            cout << fac;
            first = 0;
        }
        if (d > 1)
            cout << "^" << d;
        if (n > 1 && fac <= n)
        {
            cnt ++;
            while(n % primevector[cnt] != 0)
            {
                cnt ++;
            }
            fac = primevector[cnt];
        }
        // cout << "fac:" << fac << " n: " << n << endl;
    }
    cout << endl;
    return 0;
}