# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import List, Optional


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def chaewon(ino: List[int], posto: List[int]) -> Optional[TreeNode]:
            if len(ino) == 0:
                return None
            if len(ino) == 1:
                return TreeNode(ino[0])
            root = TreeNode(posto[-1])
            for (i, v) in enumerate(ino):
                if v == posto[-1]:
                    root.left = chaewon(ino=ino[0:i], posto=posto[0:i])
                    root.right = chaewon(
                        ino=ino[i + 1 :], posto=posto[i : len(posto) - 1]
                    )
                    break
            return root

        return chaewon(ino=inorder, posto=postorder)
