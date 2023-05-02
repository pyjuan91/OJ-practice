# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __repr__(self) -> str:
        cur = self
        res = ""
        while cur:
            res += str(cur.val) + " "
            cur = cur.next
        return res

from typing import Optional


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return Solution.chaewon(head)

    @staticmethod
    def chaewon(head: Optional[ListNode]) -> Optional[ListNode]:
        # split
        if not head or not head.next:
            return head

        left, right = Solution.split(head)

        left = Solution.chaewon(left)
        right = Solution.chaewon(right)

        sorted_list = Solution.merge(left, right)
        
        return sorted_list

    @staticmethod
    def split(a: ListNode) -> tuple:
        slow, fast = a, a.next
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next

        fast = slow.next
        slow.next = None
        return a, fast

    @staticmethod
    def merge(a: ListNode, b: ListNode) -> ListNode:
        res_head = cur = ListNode()

        while a and b:
            if a.val <= b.val:
                cur.next = a
                a = a.next
            else:
                cur.next = b
                b = b.next
            cur = cur.next
            cur.next = None

        if a:
            cur.next = a
        if b:
            cur.next = b

        return res_head.next


s = Solution()
head = ListNode(3)
head = ListNode(1, head)
head = ListNode(2, head)
head = ListNode(4, head)
head = s.sortList(head=head)
print(head)
