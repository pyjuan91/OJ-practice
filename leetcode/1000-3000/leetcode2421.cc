#include <bits/stdc++.h>
using namespace std;
class DJS {
    public:
        int n;
        vector<int> parent;
        DJS(int _n) {
            n = _n;
            parent.reserve(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int FindRoot(int a) {
            if (parent[a] == a) return a;
            return parent[a] = FindRoot(parent[a]);
        }
        void Unite(int a, int b) { parent[FindRoot(a)] = FindRoot(parent[b]); }
};
class Solution {
    public:
        int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
            int n = vals.size();
            vector<vector<int>> g(n);
            DJS djs(n);

            for (auto i : edges) {
                g[i[0]].emplace_back(i[1]);
                g[i[1]].emplace_back(i[0]);
            }

            map<int, vector<int>> nodes;
            for (int i = 0; i < n; i++) {
                nodes[vals[i]].emplace_back(i);
            }

            int res = 0;
            for (auto i : nodes) {
                for (auto node : i.second) {
                    for (auto neighbor : g[node]) {
                        if (vals[neighbor] < vals[node])
                            djs.Unite(node, neighbor);
                    }
                }

                unordered_map<int, int> cnt;
                for (auto node : i.second) {
                    cnt[djs.FindRoot(node)] += 1;
                }

                for (auto i : cnt) res += i.second * (i.second + 1) / 2;
            }
            return res;
        }
};
int main(void) { return 0; }