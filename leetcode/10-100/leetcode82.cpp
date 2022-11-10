#include <iostream>
#include <queue>
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        bool checker;
        ListNode *pos, *last;
        while (head) {
            checker = false;
            while (head->next && head->next->val == head->val) {
                head = head->next;
                checker = true;
            }
            if (checker)
                head = head->next;
            else
                break;
        }
        pos = last = head;
        while (pos) {
            checker = false;
            while (pos->next && pos->next->val == pos->val) {
                pos = pos->next;
                checker = true;
            }
            if (checker) {
                last->next = pos->next;
                pos = pos->next;
            } else {
                last = pos;
                pos = pos->next;
            }
        }
        return head;
    }
};
int main(void) { return 0; }