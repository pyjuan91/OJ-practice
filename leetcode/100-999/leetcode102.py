# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional, List


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        res = []
        q1 = [root]
        q2 = []

        while q1:
            res.append([q.val for q in q1])
            for q in q1:
                if q.left:
                    q2.append(q.left)
                if q.right:
                    q2.append(q.right)
            q1 = q2
            q2 = []

        return res
