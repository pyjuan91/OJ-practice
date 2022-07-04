#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(void) {
   set<vector<int> > s;
   int T, n, m;
   cin >> T;
   while (T--) {
      s.clear();
      cin >> n;
      vector<int> v(n), cmp(n);
      for (int i = 0; i < n; i++)
         cin >> v[i];
      for (;;) {
         if (s.count(v)) {
            cout << "LOOP\n";
            break;
         }
         if (v == cmp) {
            cout << "ZERO\n";
            break;
         }
         s.insert(v);
         vector<int> tmp(n);
         for (int i = 0; i < n; i++) {
            tmp[i] = abs(v[(i + 1) % n] - v[i]);
         }
         v = tmp;
      }
   }
   return 0;
}