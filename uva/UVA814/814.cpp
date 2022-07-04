// UVa814 The Letter Carrier's Rounds
// Rujia Liu
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

void parse_address(const string& s, string& user, string& mta) {
   int k = s.find('@');
   user = s.substr(0, k);
   mta = s.substr(k + 1);
}

int main() {
   int k;
   string s, t, user1, mta1, user2, mta2;
   set<string> addr;

   // 輸入所有MTA，轉化為地址清單
   while (cin >> s && s != "*") {
      cin >> s >> k;
      while (k--) {
         cin >> t;
         addr.insert(t + "@" + s);
      }
   }

   while (cin >> s && s != "*") {
      parse_address(s, user1, mta1);  // 處理寄件者位址

      vector<string> mta;  // 所有需要連接的mta，按照輸入順序
      map<string, vector<string> > dest;  // 每個mta需要發送的使用者
      set<string> vis;
      while (cin >> t && t != "*") {
         parse_address(t, user2, mta2);  // 處理收件人位址
         if (vis.count(t))
            continue;  // 重複的收件人
         vis.insert(t);
         if (!dest.count(mta2)) {
            mta.push_back(mta2);
            dest[mta2] = vector<string>();
         }
         dest[mta2].push_back(t);
      }
      getline(cin, t);  // 把"*"這一行的Enter吃掉

      // 輸入郵件正文
      string data;
      while (getline(cin, t) && t[0] != '*')
         data += "     " + t + "\n";

      for (int i = 0; i < mta.size(); i++) {
         string mta2 = mta[i];
         vector<string> users = dest[mta2];
         cout << "Connection between " << mta1 << " and " << mta2 << endl;
         cout << "     HELO " << mta1 << "\n";
         cout << "     250\n";
         cout << "     MAIL FROM:<" << s << ">\n";
         cout << "     250\n";
         bool ok = false;
         for (int i = 0; i < users.size(); i++) {
            cout << "     RCPT TO:<" << users[i] << ">\n";
            if (addr.count(users[i])) {
               ok = true;
               cout << "     250\n";
            } else
               cout << "     550\n";
         }
         if (ok) {
            cout << "     DATA\n";
            cout << "     354\n";
            cout << data;
            cout << "     .\n";
            cout << "     250\n";
         }
         cout << "     QUIT\n";
         cout << "     221\n";
      }
   }
   return 0;
}