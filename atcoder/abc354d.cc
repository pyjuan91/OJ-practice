#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a += 1e9, b += 1e9, c += 1e9, d += 1e9;
  int lb = a / 4, rb = c / 4;
  int height = d - b;
  // cout << "lb: " << lb << " rb: " << rb << " height: " << height << '\n';
  int full_area = (rb - lb) * height * 4;
  auto cal_extra = [&](int a, int b) {
    int left_extra = 0;
    if (a % 4 == 2) {
      left_extra = height * 3;
    } else if (a % 4 == 3) {
      if (height % 2 == 0) {
        left_extra = height / 2 * 7;
      } else {
        if (d % 2 == 0) {
          left_extra = height / 2 * 7 + 4;
        } else {
          left_extra = height / 2 * 7 + 3;
        }
      }
    } else if (a % 4 == 1) {
      if (height % 2 == 0) {
        left_extra = height / 2 * 3;
      } else {
        if (d % 2 == 0) {
          left_extra = height / 2 * 3 + 1;
        } else {
          left_extra = height / 2 * 3 + 2;
        }
      }
    }
    return left_extra;
  };
  int left_extra = cal_extra(a, b);
  int right_extra = cal_extra(c, d);
  // cout << "left_extra: " << left_extra << " right_extra: " << right_extra
  //      << '\n';
  // cout << "full_area: " << full_area - left_extra + right_extra << '\n';
  cout << full_area - left_extra + right_extra << '\n';
  return 0;
}
