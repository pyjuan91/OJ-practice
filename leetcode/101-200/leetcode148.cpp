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

// class Solution {
// public:
//     ListNode* sortList(ListNode* head)
//     {
//         if (!head || !head->next)
//             return head;
//         ListNode *sortedHead, *sortedPos, *sortedNext;
//         sortedHead = sortedPos = new ListNode(0);
//         while (head) {
//             sortedPos = sortedHead;
//             bool checker = false;
//             while (sortedPos->next) {
//                 if (sortedPos->next->val >= head->val) {
//                     sortedNext = sortedPos->next;
//                     sortedPos->next = head;
//                     head = head->next;
//                     sortedPos->next->next = sortedNext;
//                     checker = true;
//                     break;
//                 }
//                 sortedPos = sortedPos->next;
//             }
//             if (!checker) {
//                 sortedPos->next = head;
//                 head = head->next;
//                 sortedPos->next->next = nullptr;
//             }
//         }
//         return sortedHead->next;
//     }
// };
class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode *fast, *slow, *prev;
        fast = slow = head;
        prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return mergeSort(left, right);
    }

    ListNode* mergeSort(ListNode* l1, ListNode* l2)
    {
        ListNode *neoHead, *pos;
        neoHead = pos = new ListNode(0);
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pos->next = l1;
                l1 = l1->next;
            } else {
                pos->next = l2;
                l2 = l2->next;
            }
            pos = pos->next;
        }
        if (l1)
            pos->next = l1;
        if (l2)
            pos->next = l2;

        pos = neoHead->next;
        delete neoHead;
        return pos;
    }
};
int main(void) { return 0; }