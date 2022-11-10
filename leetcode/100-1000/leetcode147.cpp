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
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode *sortHead, *pos, *sortPos, *prev;
        if (head == nullptr || head->next == nullptr)
            return head;
        sortHead = sortPos = new ListNode(0);
        while (head) {
            sortPos = sortHead->next;
            prev = sortHead;
            while (sortPos) {
                if (sortPos->val >= head->val) {
                    break;
                }
                prev = sortPos;
                sortPos = sortPos->next;
            }
            prev->next = head;
            head = head->next;
            prev->next->next = sortPos;
        }
        return sortHead->next;
    }
};
int main(void) { return 0; }