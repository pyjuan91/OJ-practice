// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <iterator>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;
// map<int, vector<int>> queue;
// vector<int> where;
// int main(void)
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m, cmd, a, b;
//     cin >> n >> m;
//     where.push_back(0);
//     for (int i = 1; i <= n; i++) {
//         where.push_back(i);
//     }
//     while (m--) {
//         cin >> cmd >> a >> b;
//         if (a == b)
//             continue;
//         if (cmd == 0) {
//             // deal with person a
//             int source = where[a], target = where[b];
//             vector<int>::iterator iter = find(queue[source].begin(), queue[source].end(), a);
//             queue[source].erase(iter);
//             iter = find(queue[target].begin(), queue[target].end(), b);
//             iter = next(iter);
//             queue[target].insert(iter, a);
//             where[a] = target;
//         } else {
//             for (auto i : queue[a]) {
//                 where[i] = b;
//                 queue[b].push_back(i);
//             }
//             queue[a].clear();
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         cout << "#" << i << ":";
//         for (auto j : queue[i])
//             cout << " " << j;
//         cout << "\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int where[1000005], head[1000005], tail[1000005], myNext[1000005], myPrev[1000005];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cmd, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        where[i] = i;
        head[i] = i;
        tail[i] = i;
        myNext[i] = 0;
        myPrev[i] = 0;
    }
    while (m--) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            // remove a
            if (head[where[a]] == a && tail[where[a]] == a) {
                head[a] = tail[a] = 0;
            } else if (head[where[a]] == a) {
                head[where[a]] = myNext[a];
                myPrev[myNext[a]] = 0;
            } else if (tail[where[a]] == a) {
                tail[where[a]] = myPrev[a];
                myNext[myPrev[a]] = 0;
            } else {
                int curNext = myNext[a], curPrev = myPrev[a];
                myNext[curPrev] = curNext;
                myPrev[curNext] = curPrev;
            }

            // insert a in b;
            if (tail[where[b]] == b) {
                myNext[b] = a;
                myPrev[a] = b;
                myNext[a] = 0;
                tail[where[b]] = a;
                where[a] = where[b];
            } else {
                int bNext = myNext[b];
                myNext[b] = a;
                myPrev[a] = b;
                myNext[a] = bNext;
                myPrev[bNext] = a;
                where[a] = where[b];
            }
            
        } else {
            if (head[a] == 0)
                continue;
            if (tail[b] == 0) {
                int cur = head[a];
                head[b] = tail[b] = head[a];
                while (cur) {
                    where[cur] = b;
                    tail[b] = cur;
                    cur = myNext[cur];
                }
                head[a] = tail[a] = 0;
            } else {
                int cur = head[a], cur_prev = tail[b];
                while (cur) {
                    where[cur] = b;
                    tail[b] = cur;
                    cur = myNext[cur];
                }
                myNext[cur_prev] = head[a];
                myPrev[head[a]] = cur_prev;
                head[a] = tail[a] = 0;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << "#" << i << ":";
        //     int tmp = head[i];
        //     while (tmp != 0) {
        //         cout << " " << tmp;
        //         tmp = myNext[tmp];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":";
        int tmp = head[i];
        while (tmp != 0) {
            cout << " " << tmp;
            tmp = myNext[tmp];
        }
        cout << "\n";
    }
    return 0;
}