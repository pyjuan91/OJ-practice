#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maximumValueSum(vector<vector<int>>& board) {
    const int n = board.size(), m = board[0].size();

    auto get_top_3 = [&](const vector<int>& a) -> vector<pair<int, int>> {
      vector<pair<int, int>> res;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] == INT32_MIN) continue;
        res.push_back(make_pair(a[i], i));
      }
      sort(res.rbegin(), res.rend());
      if (res.size() > 3) res.resize(3);
      return res;
    };

    vector<vector<pair<int, int>>> suff_top_3(n);
    {
      vector<int> best(m, INT32_MIN);
      for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
          best[j] = max(best[j], board[i][j]);
        }
        suff_top_3[i] = get_top_3(best);
      }
    }

    vector<vector<pair<int, int>>> pref_top_3(n);
    {
      vector<int> best(m, INT32_MIN);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          best[j] = max(best[j], board[i][j]);
        }
        pref_top_3[i] = get_top_3(best);
      }
    }

    long long res = INT64_MIN;

    for (int col = 0; col < m; col++) {
      for (int row = 1; row < n - 1; row++) {
        auto& upper_choice = pref_top_3[row - 1];
        auto& lower_choice = suff_top_3[row + 1];
        for (const auto& [value1, c1] : upper_choice) {
          if (c1 == col) continue;
          for (const auto& [value2, c2] : lower_choice) {
            if (c2 == c1 or c2 == col) continue;
            res = max(res, 1LL * board[row][col] + value1 + value2);
          }
        }
      }
    }

    return res;
  }
};

int main() { return 0; }