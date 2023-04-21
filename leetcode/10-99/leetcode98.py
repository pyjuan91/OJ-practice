# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def chaewon(
            root: TreeNode, mi: int, ma: int, most_left: bool, most_right: bool
        ):
            if not root:
                return True
            if most_left and root.val <= mi:
                return False
            if most_right and root.val >= ma:
                return False
            return chaewon(
                root=root.left,
                mi=mi,
                ma=root.val,
                most_left=most_left,
                most_right=True,
            ) and chaewon(
                root=root.right,
                mi=root.val,
                ma=ma,
                most_left=True,
                most_right=most_right,
            )

        return chaewon(root=root, mi=0, ma=0, most_left=False, most_right=False)
