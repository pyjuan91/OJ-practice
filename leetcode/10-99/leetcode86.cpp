#include <algorithm>
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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *pos = head, *last, *tmp, *neo, *neoHead;
        neoHead = neo = new ListNode;
        if (!head)
            return nullptr;
        if (head && head->val < x) {
            while (pos && pos->val < x) {
                last = pos;
                pos = pos->next;
            }
            while (pos) {
                if (pos->val < x) {
                    tmp->next = pos->next;
                    pos->next = last->next;
                    last->next = pos;
                    last = last->next;
                    pos = tmp->next;
                } else {
                    tmp = pos;
                    pos = pos->next;
                }
            }
        } else {
            while (pos) {
                if (pos->val < x) {
                    tmp->next = pos->next;
                    pos->next = nullptr;
                    neo->next = pos;
                    neo = neo->next;
                    pos = tmp->next;
                } else {
                    tmp = pos;
                    pos = pos->next;
                }
            }
            if (neoHead->next) {
                neo->next = head;
                head = neoHead->next;
            }
        }
        return head;
    }
};
int main(void) { return 0; }