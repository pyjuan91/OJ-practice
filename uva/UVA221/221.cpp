#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#define iu(i, j, k) for (int i = j; i < k; i++)
const int maxn = 100 + 5;
using namespace std;
struct building {
   int id;
   double x, y, w, d, h;
   bool operator<(const building& rhs) const {
      return x < rhs.x || (x == rhs.x && y < rhs.y);
   }
} b[maxn];
int n;
double x[2 * maxn];
bool cover(int i, double mx) {
   return b[i].x <= mx && (b[i].x + b[i].w) >= mx;
}
bool visible(int i, double mx) {
   if (!cover(i, mx))
      return false;
   iu(k, 0, n) {
      if (cover(k, mx) && b[k].y < b[i].y && b[k].h >= b[i].h)
         return false;
   }
   return true;
}
int main(void) {
   int kase = 0;
   ifstream fin("input.txt");
   ofstream fout("output2.txt");
   // while (fin >> n && n) {
   while (cin >> n && n) {
      iu(i, 0, n) {
         // fin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
         scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
         b[i].id = i + 1;
         x[i * 2] = b[i].x;
         x[i * 2 + 1] = b[i].x + b[i].w;
      }
      sort(x, x + n * 2);
      sort(b, b + n);
      int m = unique(x, x + n * 2) - x;
      // cout << m << endl;
      if (kase++)
         putchar('\n');
      printf("For map #%d, the visible buildings are numbered as follows:\n%d",
             kase, b[0].id);
      iu(i, 1, n) {
         bool vis = false;
         iu(j, 0, m - 1) {
            if (visible(i, (x[j] + x[j + 1]) / 2)) {
               vis = true;
               break;
            }
         }
         if (vis)
            printf(" %d", b[i].id);
      }
      putchar('\n');
   }
   return 0;
}

/* // UVa221 Urban Elevations
// Rujia Liu
#include <algorithm>
//#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;

const int maxn = 100 + 5;

struct Building {
   int id;
   double x, y, w, d, h;
   bool operator<(const Building& rhs) const {
      return x < rhs.x || (x == rhs.x && y < rhs.y);
   }
} b[maxn];

int n;
double x[maxn * 2];

bool cover(int i, double mx) {
   return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

// 判斷建築物i在x=mx處否可見
bool visible(int i, double mx) {
   if (!cover(i, mx))
      return false;
   for (int k = 0; k < n; k++)
      if (b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
         return false;
   return true;
}

int main() {
   int kase = 0;
   ifstream fin("input.txt");
   ofstream fout("output1.txt");
   while (fin >> n && n) {
      // while (scanf("%d", &n) == 1 && n) {
      for (int i = 0; i < n; i++) {
         fin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
         // scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d,
         // &b[i].h);
         x[i * 2] = b[i].x;
         x[i * 2 + 1] = b[i].x + b[i].w;
         b[i].id = i + 1;
      }
      sort(b, b + n);
      sort(x, x + n * 2);
      int m = unique(x, x + n * 2) - x;  // x座標排序後去重，得到m個座標

      if (kase++)
         fout << "\n";
      // printf("\n");
      fout << "For map #" << kase
           << ", the visible buildings are numbered as follows:\n"
           << b[0].id;
      // printf("For map #%d, the visible buildings are numbered as
      // follows:\n%d",
      // kase, b[0].id);
      for (int i = 1; i < n; i++) {
         bool vis = false;
         for (int j = 0; j < m - 1; j++)
            if (visible(i, (x[j] + x[j + 1]) / 2)) {
               vis = true;
               break;
            }
         if (vis)
            fout << " " << b[i].id;
         // printf(" %d", b[i].id);
      }
      fout << "\n";
      // printf("\n");
   }
   return 0;
} */
