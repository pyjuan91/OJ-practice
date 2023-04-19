# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional


class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def chaewon(cur_node: Optional[TreeNode], dir_right: bool, sum: int) -> int:
            if not cur_node:
                return sum
            left_best = chaewon(
                cur_node=cur_node.left,
                dir_right=True,
                sum=1 + sum if not dir_right else 1,
            )
            right_best = chaewon(
                cur_node=cur_node.right,
                dir_right=False,
                sum=1 + sum if dir_right else 1,
            )
            return max(left_best, right_best)

        return (
            max(
                chaewon(root, dir_right=True, sum=0),
                chaewon(root, dir_right=False, sum=0),
            )
            - 1
        )
