#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#define MAX 105;
using namespace std;
struct task {
   bool ismy;  //是不是自己的列印工作
   int p;
};
deque<struct task> qu;
int main() {
   int t, n, my, p, time;
   // ifstream cin("input.txt");
   // ofstream cout("output2.txt");
   // scanf("%d", &t);
   cin >> t;
   while (t--) {
      time = 0;
      qu.clear();
      // scanf("%d%d", &n, &my);
      cin >> n >> my;
      for (int i = 0; i < n; i++) {
         // scanf("%d", &p);
         cin >> p;
         task job;
         if (i == my) {  //標示為自己的工作
            job.ismy = true;
            job.p = p;
         } else {
            job.ismy = false;
            job.p = p;
         }
         qu.push_back(job);
      }
      while (1) {
         task tmp;
         if (!qu.empty()) {
            tmp = qu.front();
            qu.pop_front();
         }
         bool isprint = true;
         for (int i = 0; i < qu.size();
              i++) {  //測試列印佇列中是否有較高優先權的工作
            if (qu[i].p > tmp.p) {
               qu.push_back(tmp);
               isprint = false;
               break;
            }
         }
         if (isprint) {       //可以印
            if (!tmp.ismy) {  //不是自己的工作
               time++;        //增加一分鐘
            } else {          //是自己的工作
               time++;        //增加一分鐘
               // printf("%d\n", time);
               cout << time << "\n";
               break;
            }
         }
      }
   }
   // cin.close();
   // cout.close();
   return 0;
}