#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    struct Robot {
      int health, position, index;
      bool operator<(const Robot& other) const {
        return position < other.position;
      }
    };
    vector<Robot> leftRobots, rightRobots;
    for (int i = 0; i < n; i++) {
      if (directions[i] == 'L') {
        leftRobots.push_back({ healths[i], positions[i], i });
      }
      else {
        rightRobots.push_back({ healths[i], positions[i], i });
      }
    }

    sort(leftRobots.begin(), leftRobots.end());
    sort(rightRobots.begin(), rightRobots.end());

    vector<int> ans(n, INT32_MIN);
    for (int i = 0; i < leftRobots.size(); i++) {
      Robot leftRobot = leftRobots[i];
      bool survived = true;
      while (survived and !rightRobots.empty()) {
        auto it = lower_bound(rightRobots.begin(), rightRobots.end(), leftRobot);
        if (it == rightRobots.begin()) {
          break;
        }
        it--;
        if (it->health < leftRobot.health) {
          leftRobot.health--;
          rightRobots.erase(it);
        }
        else if (it->health > leftRobot.health) {
          it->health--;
          survived = false;
        }
        else {
          rightRobots.erase(it);
          survived = false;
        }
      }
      if (survived) {
        ans[leftRobot.index] = leftRobot.health;
      }
    }

    for (int i = 0; i < rightRobots.size(); i++) {
      ans[rightRobots[i].index] = rightRobots[i].health;
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (ans[i] != INT32_MIN) {
        result.push_back(ans[i]);
      }
    }
    return result;
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> positions(n), healths(n);
  string directions;
  for (int i = 0; i < n; i++) {
    cin >> positions[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> healths[i];
  }
  cin >> directions;
  Solution sol;
  vector<int> ans = sol.survivedRobotsHealths(positions, healths, directions);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
