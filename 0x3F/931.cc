#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t i = 1; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        matrix[i][j] +=
            min({(j == 0 ? INT32_MAX : matrix[i - 1][j - 1]), matrix[i - 1][j],
                 (j == n - 1 ? INT32_MAX : matrix[i - 1][j + 1])});
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};

int main() { return 0; }