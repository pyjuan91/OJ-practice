#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    vector<Node*> oldList, newList, rem;
    int IU(Node* node)
    {
        for (int i = 0; i < oldList.size(); i++) {
            if (oldList[i] == node) {
                return i;
            }
        }
        return -1;
    }

public:
    Node* copyRandomList(Node* head)
    {
        newList.clear();
        rem.clear();
        Node *pos = head, *neo = new Node(0), *neoHead = neo;
        while (pos) {
            oldList.push_back(pos);
            neo->next = new Node(pos->val);
            neo = neo->next;
            newList.push_back(neo);
            rem.push_back(pos->random);
            pos = pos->next;
        }
        for (int i = 0; i < rem.size(); i++) {
            if (rem[i] != nullptr) {
                newList[i]->random = newList[IU(rem[i])];
            }
        }
        return neoHead->next;
    }
};
int main(void)
{
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->random = head;
    Solution s;
    Node* neo;
    neo = s.copyRandomList(head);
    while (neo) {
        cout << neo->val << " ";
        neo = neo->next;
    }
    cout << endl;
    return 0;
}