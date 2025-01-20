#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<pair<int, int>> v(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[mat[i][j] - 1] = { i, j };
      }
    }
    vector<int> col(m, n), row(n, m);
    for (int i = 0; i < n * m; i++) {
      int x = v[arr[i] - 1].first, y = v[arr[i] - 1].second;
      col[y]--, row[x]--;
      if (col[y] == 0 || row[x] == 0) return i;
    }
    return -1;
  }
};

int main() {
  return 0;
}