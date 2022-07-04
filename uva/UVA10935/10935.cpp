#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
   int n;
   while (cin >> n && n) {
      queue<int> q;
      vector<int> ans;
      for (int i = 1; i <= n; i++)
         q.push(i);
      while (q.size() > 1) {
         ans.push_back(q.front());
         q.pop();
         q.push(q.front());
         q.pop();
      }
      cout << "Discarded cards:";
      int first = 1;
      for (auto i : ans) {
         if (first)
            first = 0;
         else
            cout << ",";
         cout << " " << i;
      }
      cout << "\nRemaining card: " << q.front() << "\n";
   }
   return 0;
}