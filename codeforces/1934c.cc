#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;

  auto ask = [&](int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
  };

  auto answer = [&](int x, int y) {
    cout << "! " << x << " " << y << endl;
    cout.flush();
  };

  cin >> t;
  while (t--) {
    cin >> n >> m;
    int d1 = ask(1, 1);
    pair<int, int> up_right, down_left;
    if (d1 == 0) {
      answer(1, 1);
      continue;
    }
    if (d1 == n + m - 2) {
      answer(n, m);
      continue;
    }
    if (d1 > m - 1) {
      up_right = {d1 - (m - 1) + 1, m};
    } else {
      up_right = {1, d1 + 1};
    }

    if (d1 > n - 1) {
      down_left = {n, d1 - (n - 1) + 1};
    } else {
      down_left = {d1 + 1, 1};
    }

    int d2 = ask(down_left.first, down_left.second);
    if (d2 == 0) {
      answer(down_left.first, down_left.second);
      continue;
    }

    int d3 = ask(up_right.first, up_right.second);
    if (d3 == 0) {
      answer(up_right.first, up_right.second);
      continue;
    }

    if (d2 % 2 == 1 || d3 % 2 == 1) {
      if (d2 % 2 == 1) {
        // up_right is the answer
        answer(up_right.first + d3 / 2, up_right.second - d3 / 2);
      } else {
        // down_left is the answer
        answer(down_left.first - d2 / 2, down_left.second + d2 / 2);
      }
      continue;
    }

    // remain is both even
    // test down_left
    int d4 = ask(down_left.first - d2 / 2, down_left.second + d2 / 2);
    if (d4 == 0) {
      answer(down_left.first - d2 / 2, down_left.second + d2 / 2);
      continue;
    }
    // answer is up_right
    answer(up_right.first + d3 / 2, up_right.second - d3 / 2);
  }
  return 0;
}
