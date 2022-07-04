#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void) {
   int n;
   while (cin >> n && n) {
      vector<int> from(n), to(n);
      for (int i = 0; i < n; i++)
         cin >> from[i] >> to[i];
      sort(from.begin(), from.end());
      sort(to.begin(), to.end());
      if (from == to)
         cout << "YES\n";
      else
         cout << "NO\n";
   }
   return 0;
}