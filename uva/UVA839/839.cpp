#include <cstdbool>
#include <cstdio>
#include <iostream>
using namespace std;
bool build_balance(int& w) {
   int w1, w2, d1, d2;
   bool b1 = true, b2 = true;
   scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
   if (w1 == 0)
      b1 = build_balance(w1);
   if (w2 == 0)
      b2 = build_balance(w2);
   w = w1 + w2;
   return b1 && b2 && (w1 * d1 == w2 * d2);
}
int main(void) {
   int kase, w;
   scanf("%d", &kase);
   while (kase--) {
      if (build_balance(w))
         printf("YES\n");
      else
         printf("NO\n");
      if (kase)
         putchar('\n');
   }
   return 0;
}

// #include <iostream>
// using namespace std;
// bool solve(int& W) {
//    int W1, D1, W2, D2;
//    bool b1 = true, b2 = true;
//    cin >> W1 >> D1 >> W2 >> D2;
//    if (!W1)
//       b1 = solve(W1);
//    if (!W2)
//       b2 = solve(W2);
//    W = W1 + W2;
//    return b1 && b2 && (W1 * D1 == W2 * D2);
// }

// int main() {
//    int T, W;
//    cin >> T;
//    while (T--) {
//       if (solve(W))
//          cout << "YES\n";
//       else
//          cout << "NO\n";
//       if (T)
//          cout << "\n";
//    }
//    return 0;
// }