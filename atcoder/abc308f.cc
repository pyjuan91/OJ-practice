#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<int> P(N);
  for (int& i : P) cin >> i;
  sort(P.begin(), P.end());

  vector<int> L(M), D(M);
  for (auto& i : L) cin >> i;
  for (auto& i : D) cin >> i;

  vector<int> order(M);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (L[i] != L[j]) return L[i] < L[j];
    return D[i] < D[j];
    });

  int64_t ans = 0;
  priority_queue<int> available_discounts;
  for (int i = 0, j = 0; i < N; i++) {
    while (j < M and L[order[j]] <= P[i]) {
      available_discounts.push(D[order[j]]);
      j++;
    }
    if (!available_discounts.empty())
      P[i] -= available_discounts.top(), available_discounts.pop();
    ans += 1LL * P[i];
  }

  cout << ans << '\n';
  return 0;
}
