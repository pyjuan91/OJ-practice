#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int discrete(vector<vector<int>>& intervals) {
    map<int, int> discrete;
    for (auto& interval : intervals) {
      discrete[interval[0]] = 0;
      discrete[interval[1]] = 0;
    }
    int idx = 0;
    for (auto& [key, value] : discrete) {
      value = idx++;
    }
    for (auto& interval : intervals) {
      interval[0] = discrete[interval[0]];
      interval[1] = discrete[interval[1]];
    }
    return discrete.size();
  }

  bool lexico_smaller(const set<int>& a, const set<int>& b) {
    for (auto [a_idx, b_idx] = pair(a.begin(), b.begin()); a_idx != a.end() and b_idx != b.end(); a_idx++, b_idx++) {
      if (*a_idx < *b_idx) return true;
      if (*a_idx > *b_idx) return false;
    }
    return a.size() < b.size();
  }

  struct Interval {
    int idx, start, end, weight;
    Interval(int idx, int start, int end, int weight) : idx(idx), start(start), end(end), weight(weight) {}
    bool operator<(const Interval& other) const {
      return end < other.end;
    }
  };
public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    int n = discrete(intervals);
    vector<deque<Interval>> interval_objects(4);
    for (int i = 0; i < intervals.size(); i++) {
      for (int j = 1; j <= 4; j++) {
        interval_objects[j - 1].emplace_back(i, intervals[i][0], intervals[i][1], intervals[i][2]);
      }
    }
    for (int i = 0; i < 4; i++) {
      sort(interval_objects[i].begin(), interval_objects[i].end());
    }
    vector dp(n + 1, vector(5, pair(0LL, set<int>())));
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= 4; j++) {
        if (i) dp[i][j] = dp[i - 1][j];
        while (!interval_objects[j - 1].empty() and interval_objects[j - 1].front().end == i) {
          auto [idx, start, end, weight] = interval_objects[j - 1].front();
          interval_objects[j - 1].pop_front();
          if ((start ? dp[start - 1][j - 1].first : 0LL) + weight > dp[i][j].first) {
            if (start) dp[i][j] = { dp[start - 1][j - 1].first + weight, dp[start - 1][j - 1].second };
            else dp[i][j] = { weight, {} };
            dp[i][j].second.insert(idx);
          }
          else if ((start ? dp[start - 1][j - 1].first : 0LL) + weight == dp[i][j].first) {
            set<int> new_answer = (start ? dp[start - 1][j - 1].second : set<int>());
            new_answer.insert(idx);
            if (lexico_smaller(new_answer, dp[i][j].second)) {
              dp[i][j].second = new_answer;
            }
          }
        }
      }
    }

    pair<long long, set<int>> answer = { 0LL, set<int>() };
    for (int i = 1; i <= 4; i++) {
      if (dp[n][i].first > answer.first) {
        answer = dp[n][i];
      }
      else if (dp[n][i].first == answer.first) {
        if (lexico_smaller(dp[n][i].second, answer.second)) {
          answer = dp[n][i];
        }
      }
    }
    return vector(answer.second.begin(), answer.second.end());
  }
};

int main() {
  Solution solution;
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
  }
  auto answer = solution.maximumWeight(intervals);
  for (auto& idx : answer) {
    cout << idx << ' ';
  }
  return 0;
}