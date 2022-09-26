#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node()
    {
        val = 0;
        children.clear();
    }

    Node(int val)
    {
        this->val = val;
        children.clear();
    }
};
int n, Start, End, a, b, hasSol = 0;
int route[200005], used[200005];
void helper(int pos, Node* cur)
{
    if (hasSol)
        return;
    route[pos] = cur->val;
    if (cur->val == End) {
        hasSol = 1;
        cout << route[0];
        for (int i = 1; i <= pos; i++) {
            cout << " " << route[i];
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < cur->children.size(); i++) {
        if (used[cur->children[i]->val] == 0) {
            used[cur->children[i]->val] = 1;
            helper(pos + 1, cur->children[i]);
            used[cur->children[i]->val] = 0;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Node*> nodes;

    cin >> n >> Start >> End;
    for (int i = 0; i <= n; i++) {
        Node* n = new Node(i);
        nodes.push_back(n);
        used[i] = 0;
    }
    while (cin >> a >> b) {
        nodes[a]->children.push_back(nodes[b]);
        nodes[b]->children.push_back(nodes[a]);
    }
    used[Start] = 1;
    helper(0, nodes[Start]);
    return 0;
}