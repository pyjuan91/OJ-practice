#include<iostream>
using namespace std;

int n, q, x1, x2, y1, y2, op;
int bit_2d[1001][1001] = {};

void point_update_2d(int x, int y, int val) {
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= n; j += j & -j) {
      bit_2d[i][j] += val;
    }
  }
}

int prefix_query_2d(int x, int y) {
  int sum = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) {
      sum += bit_2d[i][j];
    }
  }
  return sum;
}

int range_query_2d(int x1, int y1, int x2, int y2) {
  return prefix_query_2d(x2, y2) - prefix_query_2d(x1 - 1, y2) -
         prefix_query_2d(x2, y1 - 1) + prefix_query_2d(x1 - 1, y1 - 1);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    s = " " + s;
    for (int j = 1; j <= n; j++) {
      if (s[j] == '*') {
        point_update_2d(i, j, 1);
      }
    }
  }

  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x1 >> y1;
      if (range_query_2d(x1, y1, x1, y1))
        point_update_2d(x1, y1, -1);
      else
        point_update_2d(x1, y1, 1);
    } else {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << range_query_2d(x1, y1, x2, y2) << '\n';
    }
  }

  return 0;
}
