// #include <iostream>
// #include <string>
// using namespace std;
// typedef struct node {
//    char c;
//    node* next;
// };
// int main(void) {
//    string str;
//    while (cin >> str) {
//       int len = str.size(), i = 0;
//       node *head, *rear, *now;
//       head = new node;
//       head->next = nullptr;
//       for (i; i < len; i++) {
//          if (str[i] != '[' && str[i] != ']') {
//             now = new node;
//             now->c = str[i];
//             now->next = nullptr;
//             head->next = now;
//             rear = now;
//             break;
//          }
//       }
//       i++;
//       if (head->next == nullptr) {
//          putchar('\n');
//          continue;
//       }
//       for (i; i < len; i++) {
//          if (str[i] == '[') {
//             now = head;
//          } else if (str[i] == ']') {
//             now = rear;
//          } else {
//             node* neo = new node;
//             neo->c = str[i];
//             neo->next = nullptr;
//             if (now->next != nullptr) {
//                neo->next = now->next;
//             } else {
//                rear = neo;
//             }
//             now->next = neo;
//             now = neo;
//          }
//       }
//       while (head->next != nullptr) {
//          node* cl = head;
//          head = head->next;
//          cout << head->c;
//          // delete cl;
//       }
//       putchar('\n');
//    }
//    return 0;
// }

// UVa11988 Broken Keyboard
// Rujia Liu
// #include <cstdio>
// #include <cstring>
// const int maxn = 100000 + 5;
// int last, cur, next[maxn];  // 游標位於cur號字元之後面
// char s[maxn];

// int main() {
//    while (scanf("%s", s + 1) == 1) {
//       int n = strlen(s + 1);  // 輸入保存在s[1], s[2]...中
//       last = cur = 0;
//       next[0] = 0;

//       for (int i = 1; i <= n; i++) {
//          char ch = s[i];
//          if (ch == '[')
//             cur = 0;
//          else if (ch == ']')
//             cur = last;
//          else {
//             next[i] = next[cur];
//             next[cur] = i;
//             if (cur == last)
//                last = i;  // 更新"最後一個字元"編號
//             cur = i;      // 移動游標
//          }
//       }
//       for (int i = next[0]; i != 0; i = next[i])
//          printf("%c", s[i]);
//       printf("\n");
//    }
//    return 0;
// }

#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int next[maxn];
char s[maxn];
int main(void) {
   int cur, last;
   while (scanf("%s", s + 1) != EOF) {
      next[0] = 0;
      int len = strlen(s + 1);
      cur = last = 0;
      for (int i = 1; i <= len; i++) {
         if (s[i] == '[') {
            cur = 0;
         } else if (s[i] == ']') {
            cur = last;
         } else {
            next[i] = next[cur];
            next[cur] = i;
            // if (cur == last)
            //    last++;
            // cur++;
            if (cur == last)
               last = i;  // 更新"最後一個字元"編號
            cur = i;      // 移動游標
         }
      }
      for (int i = next[0]; i != 0; i = next[i]) {
         printf("%c", s[i]);
      }
      putchar('\n');
   }
   return 0;
}