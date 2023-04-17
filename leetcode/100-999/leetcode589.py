# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


from typing import List


class Solution:
    def preorder(self, root: Node) -> List[int]:
        if not root:
            return []

        res = []

        def chaewon(cur_node: Node) -> None:
            res.append(cur_node.val)
            for child in cur_node.children:
                chaewon(child)

        chaewon(root)
        return res
