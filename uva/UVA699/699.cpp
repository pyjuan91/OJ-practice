#include <cstdbool>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10005;
int sum[maxn];
void build(int p) {
   int root;
   cin >> root;
   if (root == -1)
      return;
   sum[p] += root;
   build(p - 1), build(p + 1);
}
bool init() {
   int root;
   cin >> root;
   if (root == -1)
      return false;
   memset(sum, 0, sizeof(sum));
   int pos = maxn / 2;
   sum[pos] = root;
   build(pos - 1), build(pos + 1);
   return true;
}
int main(void) {
   int kase = 0, i;
   while (init()) {
      for (i = 0; i < maxn; i++)
         if (sum[i] != 0)
            break;
      cout << "Case " << ++kase << ":\n" << sum[i++];
      while (sum[i] != 0) {
         cout << " " << sum[i];
         i++;
      }
      cout << "\n\n";
   }
   return 0;
}