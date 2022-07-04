// #include <algorithm>
// #include <cstdio>
// #include <deque>
// #include <iostream>
// #include <string>
// using namespace std;
// int main(void) {
//    int n, t[5], q;
//    scanf("%d%d%d%d%d%d%d", &n, &t[0], &t[1], &t[2], &t[3], &t[4], &q);
//    getchar();
//    deque<int> work_dq;
//    deque<string> func[n + 5];
//    for (int i = 1; i <= n; i++) {
//       work_dq.push_back(i);
//       string cmd;
//       while (getline(cin, cmd)) {
//          func[i].push_back(cmd);
//          if (cmd == "end")
//             break;
//       }
//    }
//    while (!work_dq.empty()) {
//    }
//    return 0;
// }

// UVa210 Concurrency Simulator
// Rujia Liu
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1000;

deque<int> readyQ;
queue<int> blockQ;
int n, quantum, c[5], var[26], ip[maxn];
// ip[pid]是程式pid的目前行號。所有程式都存在prog陣列，更類似真實的情況，程式碼也更短
bool locked;
char prog[maxn][10];

void run(int pid) {
   int q = quantum;
   while (q > 0) {
      char* p = prog[ip[pid]];
      switch (p[2]) {
         case '=':
            var[p[0] - 'a'] =
                isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
            q -= c[0];
            break;
         case 'i':  // print
            printf("%d: %d\n", pid + 1, var[p[6] - 'a']);
            q -= c[1];
            break;
         case 'c':  // lock
            if (locked) {
               blockQ.push(pid);
               return;
            }
            locked = true;
            q -= c[2];
            break;
         case 'l':  // unlock
            locked = false;
            if (!blockQ.empty()) {
               int pid2 = blockQ.front();
               blockQ.pop();
               readyQ.push_front(pid2);
            }
            q -= c[3];
            break;
         case 'd':  // end
            return;
      }
      ip[pid]++;
   }
   readyQ.push_back(pid);
}

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%d %d %d %d %d %d %d\n", &n, &c[0], &c[1], &c[2], &c[3], &c[4],
            &quantum);
      memset(var, 0, sizeof(var));

      int line = 0;
      for (int i = 0; i < n; i++) {
         fgets(prog[line++], maxn, stdin);
         ip[i] = line - 1;
         while (prog[line - 1][2] != 'd')
            fgets(prog[line++], maxn, stdin);
         readyQ.push_back(i);
      }

      locked = false;
      while (!readyQ.empty()) {
         int pid = readyQ.front();
         readyQ.pop_front();
         run(pid);
      }
      if (T)
         printf("\n");
   }
   return 0;
}