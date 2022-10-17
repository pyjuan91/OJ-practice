#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, vector<int>> queue;
vector<int> where;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cmd, a, b;
    cin >> n >> m;
    where.push_back(0);
    for (int i = 1; i <= n; i++) {
        where.push_back(i);
    }
    while (m--) {
        cin >> cmd >> a >> b;
        if (a == b)
            continue;
        if (cmd == 0) {
            // deal with person a
            int source = where[a], target = where[b];
            vector<int>::iterator iter = find(queue[source].begin(), queue[source].end(), a);
            queue[source].erase(iter);
            iter = find(queue[target].begin(), queue[target].end(), b);
            iter = next(iter);
            queue[target].insert(iter, a);
            where[a] = target;
        } else {
            for (auto i : queue[a]) {
                where[i] = b;
                queue[b].push_back(i);
            }
            queue[a].clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":";
        for (auto j : queue[i])
            cout << " " << j;
        cout << "\n";
    }
    return 0;
}