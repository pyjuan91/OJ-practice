#include <bits/stdc++.h>
#include <debug.cc>
using namespace std;

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    k++;
    vector<int> gaps(n + 1);
    for (int i = 0; i < n - 1; i++) {
      gaps[i + 1] = startTime[i + 1] - endTime[i];
    }
    gaps[0] = startTime[0], gaps[n] = eventTime - endTime[n - 1];
    int res = 0, slidingWindow = 0;
    for (int i = 0; i < k; i++) {
      slidingWindow += gaps[i];
    }
    res = slidingWindow;
    for (int i = k; i <= n; i++) {
      slidingWindow += gaps[i] - gaps[i - k];
      res = max(res, slidingWindow);
    }
    return res;
  }
};

int main() {
  int n, k, eventTime;
  cin >> n >> k >> eventTime;
  vector<int> startTime(n), endTime(n);
  for (int i = 0; i < n; i++) {
    cin >> startTime[i] >> endTime[i];
  }
  Solution s;
  cout << s.maxFreeTime(eventTime, k, startTime, endTime) << endl;
  return 0;
}