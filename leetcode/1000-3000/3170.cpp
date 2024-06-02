#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string clearStars(string s) {
    struct Element {
      char c;
      size_t pos;
      bool operator<(const Element& other) const {
        if (c != other.c) return c > other.c;
        return pos < other.pos;
      };
    };
    priority_queue<Element> pq;
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] != '*') {
        pq.push({s[i], i});
      } else {
        if (!pq.empty()) {
          pq.pop();
        }
      }
    }
    string result(s.size(), '*');
    while (!pq.empty()) {
      Element e = pq.top();
      pq.pop();
      result[e.pos] = e.c;
    }
    result.erase(std::remove(result.begin(), result.end(), '*'), result.end());
    return result;
  }
};
int main() {
  string s;
  cin >> s;
  Solution sol;
  cout << sol.clearStars(s) << endl;
}