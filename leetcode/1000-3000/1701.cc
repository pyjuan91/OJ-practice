#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double ans = 0;
    int n = customers.size(), cur_time = 0;
    for (int i = 0; i < n; i++) {
      int arrival_time = customers[i][0], time_to_cook = customers[i][1];
      cur_time = max(cur_time, arrival_time);
      cur_time += time_to_cook;
      ans += 1.0 * cur_time - arrival_time;
    }
    return ans / n;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> customers = { {1,2},{2,5},{4,3} };
  cout << sol.averageWaitingTime(customers) << endl;
  return 0;
}