#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e3 + 5;

vector<string> s[maxn];
int len[200];
int main() {
   /* ifstream cin("input.txt");
   ofstream cout("output1.txt"); */
   string line, buf;
   int i = 0, j = 0;
   while (getline(cin, line)) {
      stringstream ss;
      ss << line;
      while (ss >> buf) {
         // cout << buf << endl;
         len[j] = max(len[j], (int)buf.length());
         s[i].push_back(buf);
         j++;
      }
      i++;
      j = 0;
   }
   cout << setiosflags(ios::left);
   for (int k = 0; k < i; k++) {
      for (int l = 0; l < s[k].size() - 1; l++) {
         cout << setw(len[l] + 1) << s[k][l];
      }
      cout << s[k][s[k].size() - 1] << endl;
   }
   return 0;
}