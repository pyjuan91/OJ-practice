#include <bits/stdc++.h>
using namespace std;
int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}
void answer(int i) {
  cout << "! " << i << endl;
  cout.flush();
}
void solve() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i < n; i += 2) {
    if (ask(i, i + 1) != ask(i + 1, i)) {
      if (i == 1) {
        if (ask(1, 3) != ask(3, 1)) {
          answer(1);
        } else {
          answer(2);
        }
      } else {
        if (ask(i - 1, i) != ask(i, i - 1)) {
          answer(i);
        } else {
          answer(i + 1);
        }
      }
      return;
    }
  }
  answer(n);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}