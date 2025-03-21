#include <bits/stdc++.h>
#include "debug.cc"
using namespace std;

class Solution {
private:
  array<bool, 10000> is_prime;
  void sieve() {
    is_prime.fill(true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 10000; i++) {
      if (is_prime[i]) {
        for (int j = i * i; j < 10000; j += i) {
          is_prime[j] = false;
        }
      }
    }
  }
public:
  int minOperations(int n, int m) {
    sieve();
    if (is_prime[n] or is_prime[m]) return -1;
    vector<int> dist(10000, 1e9);
    dist[n] = n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ n, n });
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u]) continue;
      if (u == m) break;
      for (int index = 1000; index >= 1; index /= 10) {
        int v = u / index;
        if (v == 1 or v % 10 == 0) continue;
        v = u - index;
        if (!is_prime[v] and dist[v] > dist[u] + v) {
          dist[v] = dist[u] + v;
          pq.push({ dist[v], v });
        }
      }
      for (int index = 1; index <= 1000; index *= 10) {
        int v = u / index;
        if (v == 0 or v % 10 == 9) continue;
        v = u + index;
        if (!is_prime[v] and dist[v] > dist[u] + v) {
          dist[v] = dist[u] + v;
          pq.push({ dist[v], v });
        }
      }
    }
    return dist[m] == 1e9 ? -1 : dist[m];
  }
};

int main() {
  Solution s;
  int n, m;
  cin >> n >> m;
  cout << s.minOperations(n, m) << endl;
  return 0;
}