#include <iostream>
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
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* pos = head;
        ListNode* last = head;
        if (head)
            pos = head->next;
        while (pos) {
            if (pos->val == val) {
                last->next = pos->next;
            } else {
                last = last->next;
            }
            pos = pos->next;
        }
        if (head && head->val == val) {
            head = head->next;
        }
        return head;
    }
};
int main(void)
{
    return 0;
}