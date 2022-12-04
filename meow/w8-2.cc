#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int maxDepth, maxNode;
vector<bool> vist(200005);
vector<int> disFromD1(200005);
vector<int> disFromD2(200005);
int flag;
void dfs(vector<vector<int>>& node, int now, int depth)
{

    if (depth > maxDepth) {
        maxDepth = depth;
        maxNode = now;
    }
    vist[now] = true;
    if (flag == 1)
        disFromD1[now] = depth;
    else if (flag == 2)
        disFromD2[now] = depth;
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
    int n, a, b, d1, d2;
    cin >> n;
    vector<vector<int>> node(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        node[a].emplace_back(b);
        node[b].emplace_back(a);
    }
    maxDepth = maxNode = 0;
    fill(vist.begin(), vist.end(), false);
    dfs(node, 1, 0);
    d1 = maxNode;
    maxDepth = maxNode = 0;
    fill(vist.begin(), vist.end(), false);
    flag = 1;
    dfs(node, d1, 0);
    // for(int i=1;i<=n;i++){
    //     cout << disFromD1[i] << " ";
    // }
    // cout << endl;
    d2 = maxNode;
    flag = 2;
    fill(vist.begin(), vist.end(), false);
    dfs(node, d2, 0);
    // for(int i=1;i<=n;i++){
    //     cout << disFromD2[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << max(disFromD1[i], disFromD2[i]) << " ";
    }
    cout << endl;

    return 0;
}