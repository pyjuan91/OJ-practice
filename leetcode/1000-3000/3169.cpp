#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    int empty_start = 1, result = 0, farthest_end = 0;
    sort(meetings.begin(), meetings.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] != b[0]) return a[0] < b[0];
           return a[1] < b[1];
         });
    for (auto& meeting : meetings) {
      if (meeting[0] > empty_start) {
        result += meeting[0] - empty_start;
      }
      farthest_end = max(farthest_end, meeting[1]);
      empty_start = farthest_end + 1;
    }
    if (empty_start <= days) {
      result += days - empty_start + 1;
    }
    return result;
  }
};
int main() {
  int days, n;
  cin >> days >> n;
  vector<vector<int>> meetings(n, vector<int>(2));
  for (auto& meeting : meetings) {
    cin >> meeting[0] >> meeting[1];
  }
  Solution sol;
  cout << sol.countDays(days, meetings) << endl;
}