// #include <algorithm>
// #include <cstdio>
// #include <fstream>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// int main(void) {
//    // ifstream cin("input.txt");
//    // ofstream cout("output1.txt");
//    int n, m, x, pos, pv, keypos, value, cnt, c_front, c_back, ans;
//    cin >> n;
//    while (n--) {
//       cin >> m >> pos;
//       vector<int> v;
//       for (int i = 0; i < m; i++) {
//          cin >> x;
//          v.push_back(x);
//          if (i == pos)
//             pv = x;
//       }
//       keypos = -1;
//       value = 10;
//       cnt = c_front = c_back = ans = 0;
//       for (int i = 0; i < m; i++) {
//          if (v[i] > pv) {
//             cnt++;
//             if (v[i] <= value) {
//                keypos = i;
//                value = v[i];
//             }
//          }
//       }
//       if (keypos == -1) {
//          for (int i = 0; i <= pos; i++) {
//             if (v[i] == pv)
//                ans++;
//          }
//       } else if (pos > keypos) {
//          for (int i = keypos; i <= pos; i++) {
//             if (v[i] == pv)
//                ans++;
//          }
//          ans += cnt;
//       } else {
//          for (int i = 0; i < m; i++) {
//             if (i >= 0 && i <= pos && v[i] == pv)
//                ans++;
//             else if (i >= keypos && i < m && v[i] == pv)
//                ans++;
//          }
//          ans += cnt;
//       }
//       cout << ans << "\n";
//    }
//    // cin.close();
//    // cout.close();
//    return 0;
// }
//
#include <deque>
#include <iostream>
#include <queue>
using namespace std;
typedef struct {
   bool check;
   int value;
} member;
int main(void) {
   int n, m, x, pos, time, can_print;
   cin >> n;
   while (n--) {
      cin >> m >> pos;
      deque<member> dq;
      for (int i = 0; i < m; i++) {
         member tmp;
         cin >> tmp.value;
         if (i == pos)
            tmp.check = true;
         else
            tmp.check = false;
         dq.push_back(tmp);
      }
      time = 0;
      for (;;) {
         member tmp = dq.front();
         dq.pop_front();
         can_print = 1;
         for (int i = 0; i < dq.size(); i++) {
            if (dq[i].value > tmp.value) {
               can_print = 0;
               break;
            }
         }
         if (can_print) {
            time++;
            if (tmp.check) {
               cout << time << "\n";
               break;
            }
         } else {
            dq.push_back(tmp);
         }
      }
   }
   return 0;
}