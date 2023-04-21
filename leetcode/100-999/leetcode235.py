# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        p_parent, q_parent = [], []

        def chaewon(root: TreeNode, parent: list, target: TreeNode):
            if not root:
                return False
            parent.append(root)
            if root == target:
                return True
            if chaewon(root=root.left, parent=parent, target=target):
                return True
            if chaewon(root=root.right, parent=parent, target=target):
                return True
            parent.pop()
            return False

        chaewon(root=root, parent=p_parent, target=p)
        chaewon(root=root, parent=q_parent, target=q)

        res = root
        for i in range(min(len(p_parent), len(q_parent))):
            if p_parent[i] == q_parent[i]:
                res = p_parent[i]
            else:
                break
        return res
