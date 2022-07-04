#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<int> length;
map<int, vector<string> > m;
vector<string> neo;
int get_max_counts_and_renew_the_length(const vector<string>& v) {
   int ans, max_ans = -1, cnt = 0;
   for (auto it : v) {
      cnt++;
      ans = 0;
      stringstream ss;
      string tmp;
      ss << it;
      while (ss >> tmp) {
         m[cnt].push_back(tmp);
         ans++;
         if ((int)length.size() < ans)
            length.push_back((int)tmp.length());
         else
            length[ans - 1] = max(length[ans - 1], (int)tmp.length());
      }
      max_ans = max(ans, max_ans);
   }
   return max_ans;
}
void print(int num, int max_count) {
   for (int i = 1; i <= num; i++) {
      int first = 1, cnt = 0;
      for (int j = 0; j < m[i].size() - 1; j++) {
         if (first)
            first = 0;
         else
            putchar(' ');
         // fprintf(fout, " ");
         const char* ptr;
         ptr = (m[i][j].c_str());
         // fprintf(fout, "%-*s", length[cnt++], ptr);
         printf("%-*s", length[cnt++], ptr);
      }
      cout << m[i][m[i].size() - 1];
      putchar('\n');
      // fprintf(fout, "\n");
   }
   // fclose(fout);
}
int main(void) {
   string s;
   vector<string> v;
   int num = 0;
   // ifstream cin("input.txt");
   while (getline(cin, s)) {
      v.push_back(s);
      num++;
   }
   int max_count = get_max_counts_and_renew_the_length(v);
   print(num, max_count);
   return 0;
}

// #include <bits/stdc++.h>
// #define INF 0x3f3f3f3f
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// using namespace std;
// typedef long long LL;
// typedef pair<int, int> P;
// const int maxn = 1e3 + 5;

// vector<string> s[maxn];
// int len[200];
// int main() {
//    /* ifstream cin("input.txt");
//    ofstream cout("output1.txt"); */
//    string line, buf;
//    int i = 0, j = 0;
//    while (getline(cin, line)) {
//       stringstream ss;
//       ss << line;
//       while (ss >> buf) {
//          // cout << buf << endl;
//          len[j] = max(len[j], (int)buf.length());
//          s[i].push_back(buf);
//          j++;
//       }
//       i++;
//       j = 0;
//    }
//    cout << setiosflags(ios::left);
//    for (int k = 0; k < i; k++) {
//       for (int l = 0; l < s[k].size() - 1; l++) {
//          cout << setw(len[l] + 1) << s[k][l];
//       }
//       cout << s[k][s[k].size() - 1] << endl;
//    }
//    return 0;
// }

// #include <algorithm>
// #include <cstring>
// #include <iomanip>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>
// using namespace std;
// const int maxn = 1005;
// vector<string> v[maxn];
// int length[200] = {};
// int main(void) {
//    string s;
//    int i = 0, j = 0;
//    while (getline(cin, s)) {
//       stringstream ss;
//       ss << s;
//       string buf;
//       while (ss >> buf) {
//          length[j] = max(length[j], (int)buf.length());
//          v[i].push_back(buf);
//          j++;
//       }
//       j = 0;
//       i++;
//    }
//    cout << setiosflags(ios::left);
//    for (int k = 0; k < i; k++) {
//       for (int m = 0; m < v[k].size() - 1; m++) {
//          cout << setw(length[m] + 1) << v[k][m];
//       }
//       cout << v[k][v[k].size() - 1] << endl;
//    }
//    return 0;
// }