#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
bool atLeastOne(vector<int>& a, int q)
{
    for (auto i : a)
        if (i == q)
            return true;
    return false;
}
int canMeasureWater(vector<int>& a, int targetCapacity, int n)
{
    queue<vector<int>> Q;
    queue<int> rec;
    set<vector<int>> Visited;
    Q.emplace(vector<int>(n));
    rec.emplace(0);
    while (Q.size()) {
        auto cur = Q.front();
        int step = rec.front();
        Q.pop();
        rec.pop();

        if (Visited.count(cur))
            continue;

        if (atLeastOne(cur, targetCapacity))
            return step;

        Visited.emplace(cur);
        
        for (int i = 0; i < n; i++) {
            auto neo = cur;
            neo[i] = a[i];
            Q.emplace(neo); // full one of it
            rec.emplace(step + 1);
            neo[i] = 0;
            Q.emplace(neo); // empty one of it
            rec.emplace(step + 1);

            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                int jNew = min(cur[i] + cur[j], a[j]);
                int iNew = min(cur[i] + cur[j], a[i]);
                neo = cur;
                neo[j] = jNew;
                neo[i] = cur[i] + cur[j] - jNew;
                Q.emplace(neo);
                rec.emplace(step + 1);
                neo = cur;
                neo[i] = iNew;
                neo[j] = cur[i] + cur[j] - iNew;
                Q.emplace(neo);
                rec.emplace(step + 1);
            }
        }
    }
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;

    cout << canMeasureWater(a, q, n) << "\n";
    return 0;
}