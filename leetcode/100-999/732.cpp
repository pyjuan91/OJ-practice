#include <bits/stdc++.h>
using namespace std;
class MyCalendarThree {
 public:
  map<int, int> m;
  MyCalendarThree() { m.clear(); }

  int book(int startTime, int endTime) {
    m[startTime]++;
    m[endTime]--;
    int res = 0, pre = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      pre += it->second;
      res = max(res, pre);
    }
    return res;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

int main() {
  auto obj = new MyCalendarThree();
  cout << obj->book(10, 20) << endl;
  cout << obj->book(50, 60) << endl;
  cout << obj->book(10, 40) << endl;
  cout << obj->book(5, 15) << endl;
  cout << obj->book(5, 10) << endl;
  cout << obj->book(25, 55) << endl;
  return 0;
}