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
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || (head && !head->next))
            return head;
        ListNode *neo, *pos, *tmp, *last;
        pos = head, neo = head->next;
        while (pos && pos->next) {
            if (pos != head)
                last->next = pos->next;
            tmp = pos->next;
            pos->next = tmp->next;
            tmp->next = pos;
            last = pos;
            pos = pos->next;
        }
        return neo;
    }
};
int main(void)
{
    return 0;
}