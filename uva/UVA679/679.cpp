// #include <cmath>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// int orbit[10000005];
// int main(void) {
//    int n, dep, id;
//    scanf("%d", &n);
//    while (n--) {
//       scanf("%d%d", &dep, &id);
//       memset(orbit, 0, sizeof(orbit));
//       int range = pow(2, dep) - 1, ans;
//       for (int i = 0; i < id; i++) {
//          int k = 1;
//          for (;;) {
//             ans = k;
//             orbit[k] = !orbit[k];
//             if (orbit[k])
//                k *= 2;
//             else
//                k = k * 2 + 1;
//             if (k > range)
//                break;
//          }
//       }
//       printf("%d\n", ans);
//    }
//    scanf("%d", &n);
//    return 0;
// }

#include <cstdio>
int main() {
   int T, D, I;
   scanf("%d", &T);
   while (T--) {
      scanf("%d%d", &D, &I);
      int k = 1;
      for (int i = 0; i < D - 1; i++)
         if (I % 2) {
            k = k * 2;
            I = (I + 1) / 2;
         } else {
            k = k * 2 + 1;
            I /= 2;
         }
      printf("%d\n", k);
   }
   return 0;
}