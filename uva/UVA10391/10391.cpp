#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(void) {
   string str;
   set<string> s;
   while (cin >> str)
      s.insert(str);
   for (auto it : s) {
      if (it.length() == 1)
         continue;
      for (int i = 1; i < it.size(); i++) {
         string tmp1 = it.substr(0, i);
         string tmp2 = it.substr(i, it.size() - i);
         if (s.count(tmp1) && s.count(tmp2)) {
            cout << it << "\n";
            break;
         }
      }
   }
   return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//    string word, tmp1, tmp2;
//    vector<string> vec;
//    while (cin >> word)
//       vec.push_back(word);
//    sort(vec.begin(), vec.end());
//    for (int x = 0; x < vec.size(); x++) {
//       if (vec[x].size() == 1)
//          continue;
//       for (int y = 1; y < vec[x].size(); y++) {
//          tmp1 = vec[x].substr(0, y);
//          tmp2 = vec[x].substr(y, vec[x].size() - 1);
//          // cout<<tmp1<<" n "<<tmp2<<endl;
//          if (binary_search(vec.begin(), vec.end(), tmp1) &&
//              binary_search(vec.begin(), vec.end(), tmp2)) {
//             printf("%s\n", vec[x].c_str());
//             break;
//          }
//       }
//    }
//    return 0;
// }