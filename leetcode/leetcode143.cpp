#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
class Solution {
private:
    vector<ListNode*> v;

public:
    void reorderList(ListNode* head)
    {
        v.clear();
        ListNode* pos = head;
        while (pos) {
            v.push_back(pos);
            pos = pos->next;
        }
        pos = head;
        for (int i = 0; i < v.size() / 2; i++) {
            pos->next = v[i];
            v[i]->next = v[v.size() - 1 - i];
            if (i == 0)
                pos = pos->next;
            else {
                pos = pos->next->next;
            }
        }
        if (v.size() % 2) {
            pos->next = v[v.size() / 2];
            v[v.size() / 2]->next = nullptr;
        } else {
            pos->next = nullptr;
        }
    }
};
int main(void)
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    s.reorderList(head);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}