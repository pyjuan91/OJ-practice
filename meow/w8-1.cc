#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int maxDepth, maxNode;
vector<bool> vist(200005);
void dfs(vector<vector<int>>& node, int now, int depth)
{

    if (depth > maxDepth) {
        maxDepth = depth;
        maxNode = now;
    }
    vist[now] = true;
    for (auto i : node[now]) {
        if (vist[i] == false) {
            dfs(node, i, depth + 1);
        }
    }
    return;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    vector<vector<int>> node(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        node[a].emplace_back(b);
        node[b].emplace_back(a);
    }
    // for(auto i: node){
    //     for(auto j: i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    maxDepth = maxNode = 0;
    fill(vist.begin(), vist.end(), false);
    dfs(node, 1, 0);
    fill(vist.begin(), vist.end(), false);
    dfs(node, maxNode, 0);
    cout << maxDepth << endl;
    return 0;
}