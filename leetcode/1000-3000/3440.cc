#include <bits/stdc++.h>

#include "debug.cc"
using namespace std;

class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<int> gaps = {startTime[0]};
    for (int i = 1; i < n; i++) gaps.push_back(startTime[i] - endTime[i - 1]);
    gaps.push_back(eventTime - endTime[n - 1]);
    map<int, int> gapCount;
    for (int gap : gaps) gapCount[gap]++;
    int res = 0;
    for (int i = 0; i < n; i++) {
      int curWidth = endTime[i] - startTime[i];
      int leftGap = gaps[i];
      int rightGap = gaps[i + 1];
      gapCount[leftGap]--;
      gapCount[rightGap]--;
      if (gapCount[leftGap] == 0) gapCount.erase(leftGap);
      if (gapCount[rightGap] == 0) gapCount.erase(rightGap);
      auto it = gapCount.lower_bound(curWidth);
      if (it != gapCount.end()) {
        res = max(res, curWidth + leftGap + rightGap);
      } else {
        res = max(res, leftGap + rightGap);
      }
      gapCount[leftGap]++;
      gapCount[rightGap]++;
    }
    return res;
  }
};

int main() {
  int n, eventTime;
  cin >> n >> eventTime;
  vector<int> startTime(n), endTime(n);
  for (int i = 0; i < n; i++) {
    cin >> startTime[i] >> endTime[i];
  }
  Solution solution;
  cout << solution.maxFreeTime(eventTime, startTime, endTime) << endl;
  return 0;
}