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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (!head || !head->next || left == right)
            return head;
        ListNode *rev = nullptr, *revHead, *pos = head, *start = nullptr, *revTail;
        int cnt = 0;
        while (pos) {
            cnt++;
            if (cnt == left) {
                while (cnt <= right) {
                    revHead = new ListNode(pos->val, rev);
                    if (!rev)
                        revTail = revHead;
                    rev = revHead;
                    pos = pos->next;
                    cnt++;
                }
                revTail->next = pos;
                if (start) {
                    start->next = revHead;
                    
                } else {
                    head = revHead;
                }
                break;
            }
            start = pos;
            pos = pos->next;
        }
        return head;
    }
};
int main(void) { return 0; }