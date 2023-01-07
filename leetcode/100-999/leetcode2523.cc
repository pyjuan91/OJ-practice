#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> primes;
    vector<bool> is_prime;
    void seive(int n)
    {
        primes.clear();
        is_prime.assign(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i])
                primes.emplace_back(i);
            for (auto p : primes) {
                if (1LL * p * i > n)
                    break;
                is_prime[p * i] = false;
                if (i % p == 0)
                    break;
            }
        }
    }
    vector<int> closestPrimes(int left, int right)
    {
        seive(right);
        auto iter = lower_bound(primes.begin(), primes.end(), left);
        if (iter == primes.end())
            return { -1, -1 };
        int prev = *iter, ans = 1e7;
        vector<int> p(2, 0);
        iter++;
        while (iter != primes.end() && *iter <= right) {
            if ((*iter - prev) < ans) {
                ans = *iter - prev;
                p[0] = prev;
                p[1] = *iter;
            }
            prev = *iter;
            iter++;
        }
        if (ans == 1e7)
            p[0] = p[1] = -1;
        return p;
    }
};
int main(void) { return 0; }