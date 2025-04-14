#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (size_t i = 1; i < triangle.size(); i++) {
      for (size_t j = 0; j < triangle[i].size(); j++) {
        if (j == 0) {
          triangle[i][j] += triangle[i - 1][j];
        } else if (j == triangle[i].size() - 1) {
          triangle[i][j] += triangle[i - 1][j - 1];
        } else {
          triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
      }
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};

int main() { return 0; }