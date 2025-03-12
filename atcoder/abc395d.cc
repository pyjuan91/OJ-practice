#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q, op, a, b;
  cin >> n >> q;
  vector<int> position(n + 1), superface(n + 1), insidereal(n + 1);
  iota(position.begin(), position.end(), 0);
  iota(superface.begin(), superface.end(), 0);
  iota(insidereal.begin(), insidereal.end(), 0);

  while (q--) {
    cin >> op >> a;
    if (not (op == 3)) cin >> b;

    if (op == 1) {
      position[a] = superface[b];
    }
    else if (op == 2) {
      int x = superface[a];
      int y = superface[b];
      superface[a] = y;
      superface[b] = x;
      insidereal[y] = a;
      insidereal[x] = b;
    }
    else {
      cout << insidereal[position[a]] << endl;
    }
  }
  return 0;
}