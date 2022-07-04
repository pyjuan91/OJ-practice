#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef struct node {
   string t, a;
   bool operator<(const node& rhs) const {
      return a < rhs.a || (a == rhs.a && t < rhs.t);
   }
   bool operator>(const node& rhs) const {
      return a > rhs.a || (a == rhs.a && t > rhs.t);
   }
} book;
map<string, string> T_A;
set<book> shelves;
priority_queue<book, vector<book>, greater<book> > returned;
book GetTitleAndAuthor(string& cmd) {
   book tmp;
   int i;
   for (i = 1; i < cmd.size(); i++) {
      if (cmd[i] == '\"')
         break;
   }
   tmp.t = cmd.substr(0, i + 1);
   tmp.a = cmd.substr(i + 5, cmd.size() - i - 5);
   T_A[tmp.t] = tmp.a;
   return tmp;
}
int main(void) {
   // ifstream cin("input.txt");
   // ofstream cout("output1.txt");
   string cmd;
   while (getline(cin, cmd) && cmd != "END") {
      shelves.insert(GetTitleAndAuthor(cmd));
   }
   // for (auto i : shelves)
   //    cout << i.t << " GO " << i.a << endl;
   while (cin >> cmd) {
      if (cmd == "BORROW") {
         getchar();
         getline(cin, cmd);
         book tmp;
         tmp.t = cmd;
         tmp.a = T_A[cmd];
         shelves.erase(tmp);
         // for (auto it : shelves) {
         //    cout << it.t << endl;
         // }
      } else if (cmd == "RETURN") {
         getchar();
         getline(cin, cmd);
         book tmp;
         tmp.t = cmd;
         tmp.a = T_A[cmd];
         returned.push(tmp);
      } else if (cmd == "SHELVE") {
         if (returned.empty()) {
            cout << "END\n";
            continue;
         }
         auto check = shelves.begin();
         if (shelves.empty()) {
            cout << "Put " << returned.top().t << " first\n";
            shelves.insert(returned.top());
            returned.pop();
         } else if ((*check).a > returned.top().a ||
                    ((*check).a == returned.top().a &&
                     (*check).t > returned.top().t)) {
            cout << "Put " << returned.top().t << " first\n";
            shelves.insert(returned.top());
            returned.pop();
         }
         while (!returned.empty()) {
            cout << "Put " << returned.top().t << " after ";
            string smaller_t;
            for (auto it : shelves) {
               if (it.a > returned.top().a ||
                   (it.a == returned.top().a && it.t > returned.top().t))
                  break;
               smaller_t = it.t;
            }
            cout << smaller_t << "\n";
            shelves.insert(returned.top());
            returned.pop();
         }
         cout << "END\n";
      } else if (cmd == "END") {
         break;
      }
   }
   // cin.close();
   // cout.close();
   return 0;
}