#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* mergeNodes(struct ListNode* head) {
  typedef struct ListNode ListNode;
  ListNode* cur = head;
  while (cur != NULL) {
    while (cur->next != NULL && cur->next->val != 0) {
      cur->val += cur->next->val;
      cur->next = cur->next->next;
      if (cur->next->next == NULL) {
        cur->next = NULL;
      }
    }
    cur = cur->next;
  }
  return head;
}

int main() {}