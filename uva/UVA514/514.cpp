#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(void) {
   int n, first = 1;
   while (cin >> n && n) {
      int x;
      for (;;) {
         cin >> x;
         if (x == 0) {
            putchar('\n');
            break;
         }
         deque<int> q, qq, qqq;
         stack<int> s;
         q.push_back(x);
         for (int i = 0; i < n - 1; i++) {
            cin >> x;
            q.push_back(x);
         }
         qqq = q;
         for (int i = 1; i <= n; i++) {
            if (q.front() == i) {
               q.pop_front();
               qq.push_back(i);
               while (!s.empty() && q.front() == s.top()) {
                  q.pop_front();
                  qq.push_back(s.top());
                  s.pop();
               }
            } else
               s.push(i);
         }
         if (qq == qqq)
            cout << "Yes\n";
         else
            cout << "No\n";
      }
   }
   return 0;
}

// UVa514 Rails
// Rujia Liu
// #include <cstdio>
// #include <stack>
// using namespace std;
// const int MAXN = 1000 + 10;

// int n, target[MAXN];

// int main() {
//    while (scanf("%d", &n) == 1 && n) {
//       while (scanf("%d", &target[1])) {
//          if (target[1] == 0) {
//             putchar('\n');
//             break;
//          }
//          stack<int> s;
//          int A = 1, B = 1;
//          for (int i = 2; i <= n; i++)
//             scanf("%d", &target[i]);
//          int ok = 1;
//          while (B <= n) {
//             if (A == target[B]) {
//                A++;
//                B++;
//             } else if (!s.empty() && s.top() == target[B]) {
//                s.pop();
//                B++;
//             } else if (A <= n)
//                s.push(A++);
//             else {
//                ok = 0;
//                break;
//             }
//          }
//          printf("%s\n", ok ? "Yes" : "No");
//       }
//    }
//    return 0;
// }