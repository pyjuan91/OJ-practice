#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, string> book;  // title -> author;
vector<string> lef, shel;
const int maxn = 5000 + 10;
const string big = "{{{";
struct books {
   string title, author;
} bok[maxn], shel_bok[maxn];
bool cmp(const books& a, const books& b) {
   return a.author < b.author || (a.author == b.author && a.title < b.title);
}

void deal(ofstream& cout) {
   int lef_size = lef.size(), shel_size = shel.size();
   for (int i = 0; i < lef_size; ++i) {
      bok[i].title = lef[i];
      bok[i].author = book[lef[i]];
   }
   for (int i = 0; i < shel_size; ++i) {
      shel_bok[i].title = shel[i];
      shel_bok[i].author = book[shel[i]];
   }
   sort(bok, bok + lef_size, cmp);
   sort(shel_bok, shel_bok + shel_size, cmp);
   for (int i = 0; i < shel_size; ++i) {
      int pos = 0;
      while ((shel_bok[i].author > bok[pos].author ||
              (shel_bok[i].author == bok[pos].author &&
               shel_bok[i].title > bok[pos].title)))
         ++pos;
      if (!pos)
         cout << "Put " << shel_bok[i].title << " first" << endl;
      else
         cout << "Put " << shel_bok[i].title << " after " << bok[pos - 1].title
              << endl;
      bok[lef_size].title = shel_bok[i].title;
      bok[lef_size].author = shel_bok[i].author;
      lef_size++;
      lef.push_back(shel_bok[i].title);
      sort(bok, bok + lef_size, cmp);
   }
   cout << "END" << endl;
   shel.clear();
   // cout.close();
}
int main() {
   ofstream cout("output2.txt");
   string s, key, value, t;
   book["{{{"] = "{{{";
   while (getline(cin, s) && s != "END") {
      int m = s.find("by");
      key = s.substr(0, m - 1);
      value = s.substr(m + 3);
      book[key] = value;
      lef.push_back(key);
   }
   while (getline(cin, s) && s != "END") {
      int m = s.find("\"");  // find "
      if (m == -1)
         deal(cout);
      else {
         t = s.substr(0, m - 1);
         value = s.substr(m);
         if (t == "BORROW") {
            vector<string>::iterator it = find(lef.begin(), lef.end(), value);
            if (it != lef.end())
               *it = big;
         } else
            shel.push_back(value);
      }
   }
   return 0;
}