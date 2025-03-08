#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int64_t A, B;
  cin >> A >> B;

  auto f = [](int64_t x) ->int64_t {
    if (x < 0) return 0;
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
    };

  cout << (f(B) ^ f(A - 1)) << '\n';
  return 0;
}