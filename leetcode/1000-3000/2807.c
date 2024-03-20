#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
  struct ListNode* cur = head;
  while (cur->next != NULL) {
    struct ListNode* next = cur->next;
    struct ListNode* new_node =
        (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = gcd(cur->val, next->val);
    new_node->next = next;
    cur->next = new_node;
    cur = next;
  }
  return head;
}

int main() {}