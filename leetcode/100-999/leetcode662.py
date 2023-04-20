# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = [(root, 0)]
        child = []
        res = 1

        while queue:
            if len(queue) > 1:
                res = max(res, queue[-1][1] - queue[0][1] + 1)

            for node, pos in queue:
                if node.left:
                    child.append((node.left, pos * 2))
                if node.right:
                    child.append((node.right, pos * 2 + 1))
            
            queue = child
            child = []
        
        return res
