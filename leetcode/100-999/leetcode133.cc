#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    int used[105];
    Node* rec[105];
    Node* dfs(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        Node* neo = new Node(node->val);
        used[node->val] = 1;
        rec[node->val] = neo;
        for (Node* nei : node->neighbors) {
            if (used[nei->val] == 1) {
                neo->neighbors.push_back(rec[nei->val]);
                continue;
            }
            neo->neighbors.push_back(dfs(nei));
        }
        return neo;
    }
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        return dfs(node);
    }
};
int main(void) { return 0; }