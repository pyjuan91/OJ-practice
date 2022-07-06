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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 != nullptr && list2 != nullptr) {
                if (list1->val <= list2->val) {
                    ans->next = new ListNode(list1->val);
                    list1 = list1->next;
                } else {
                    ans->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
            } else if (list1 == nullptr) {
                ans->next = list2;
                break;
            } else {
                ans->next = list1;
                break;
            }
            ans = ans->next;
        }
        return head->next;
    }
};
int main(void)
{
    ListNode* list1 = new ListNode(4);
    list1 = new ListNode(2, list1);
    list1 = new ListNode(1, list1);
    ListNode* list2 = new ListNode(4);
    list2 = new ListNode(3, list2);
    list2 = new ListNode(1, list2);
    Solution s;
    ListNode* ans = s.mergeTwoLists(list1, list2);
    while (ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}