#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> cups(101, vector<double>(101, 0));
    cups[0][0] = static_cast<double>(poured);
    for (int r = 0; r <= query_row; r++) {
      for (int c = 0; c <= query_glass; c++) {
        if (cups[r][c] < 1.0) continue;
        double nxt = (cups[r][c] - 1.0) / 2;
        cups[r][c] = 1.0;
        cups[r + 1][c] += nxt;
        cups[r + 1][c + 1] += nxt;
      }
    }
    return cups[query_row][query_glass];
  }
};

int main() { return 0; }