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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (l1->val == 0 && l1->next == nullptr)
            return l2;
        if (l2->val == 0 && l2->next == nullptr)
            return l1;
        int carry = 0;
        ListNode *rec1 = l1, *rec2 = l2, *last;
        while (l1 && l2) {
            l2->val = l1->val + l2->val + carry;
            carry = l2->val / 10;
            l2->val %= 10;
            l1->val = l2->val;
            last = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr) {
            if (carry) {
                if (l2 == nullptr)
                    last->next = new ListNode(1);
                else {
                    if (l2->val == 9) {
                        while (l2) {
                            l2->val += carry;
                            carry = l2->val / 10;
                            l2->val %= 10;
                            last = l2;
                            l2 = l2->next;
                        }
                        if (carry)
                            last->next = new ListNode(1);
                    } else {
                        l2->val += 1;
                    }
                }
            }
            return rec2;
        } else {
            if (carry) {
                if (l1->val == 9) {
                    while (l1) {
                        l1->val += carry;
                        carry = l1->val / 10;
                        l1->val %= 10;
                        last = l1;
                        l1 = l1->next;
                    }
                    if (carry)
                        last->next = new ListNode(1);
                } else {
                    l1->val += 1;
                }
            }
            return rec1;
        }
    }
};
int main(void)
{
    return 0;
}