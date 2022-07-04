#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn];  // 游標位於cur號字元之後面
char s[maxn];

int main() {
   while (scanf("%s", s + 1) == 1) {
      int n = strlen(s + 1);  // 輸入保存在s[1], s[2]...中
      last = cur = 0;
      next[0] = 0;

      for (int i = 1; i <= n; i++) {
         char ch = s[i];
         if (ch == '[')
            cur = 0;
         else if (ch == ']')
            cur = last;
         else {
            next[i] = next[cur];
            next[cur] = i;
            if (cur == last)
               last = i;  // 更新"最後一個字元"編號
            cur = i;      // 移動游標
         }
      }
      for (int i = next[0]; i != 0; i = next[i])
         printf("%c", s[i]);
      printf("\n");
   }
   return 0;
}