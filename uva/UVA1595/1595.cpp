#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1005;
struct point {
   int x, y;
   bool operator<(const point& rhs) const {
      return x < rhs.x || (x == rhs.x && y < rhs.y);
   }
} p[maxn];
double midx;
bool neo_cmp(const point& lhs, const point& rhs) {
   if (lhs.x < midx && rhs.x < midx) {
      return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y > rhs.y);
   }
   return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}
int main(void) {
   int n, m;
   cin >> n;
   while (n--) {
      cin >> m;
      for (int i = 0; i < m; i++)
         cin >> p[i].x >> p[i].y;
      sort(p, p + m);

      if (m % 2 == 1)
         midx = (double)p[m / 2].x;
      else
         midx = (double)(p[m / 2].x + p[m / 2 - 1].x) / 2.0;
      sort(p, p + m, neo_cmp);
      int flag = 1;
      for (int i = 0; i < m / 2; i++) {
         if (p[i].x == midx && p[m - 1 - i].x == midx)
            continue;
         if (p[i].y != p[m - 1 - i].y ||
             midx - (double)p[i].x != (double)p[m - 1 - i].x - midx) {
            flag = 0;
            break;
         }
      }
      if (flag)
         cout << "YES\n";
      else
         cout << "NO\n";
   }
   return 0;
}