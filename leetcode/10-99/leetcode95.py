# Definition for a binary tree node.
import copy
from typing import List, Optional
from copy import deepcopy


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:

        def chaewon(l: int, r: int):
            res = []
            if l == r:
                res.append(TreeNode(l))
                return res
            for root in range(l, r+1):
                curTree = TreeNode(root)
                if root == l:
                    right = chaewon(l+1, r)
                    for rightSubTree in right:
                        curTree.right = rightSubTree
                        # traverse(curTree)
                        # print()
                        res.append(deepcopy(curTree))
                elif root == r:
                    left = chaewon(l, r-1)
                    for leftSubTree in left:
                        curTree.left = leftSubTree
                        # traverse(curTree)
                        # print()
                        res.append(deepcopy(curTree))

                else:
                    left = chaewon(l, root-1)
                    right = chaewon(root+1, r)
                    for lst in left:
                        for rst in right:
                            curTree.left = lst
                            curTree.right = rst
                            # traverse(curTree)
                            # print()
                            res.append(deepcopy(curTree))

            return res

        return chaewon(1, n)


def traverse(root: TreeNode):
    if root == None:
        print("null", end=" ")
        return
    traverse(root.left)
    print(root.val, end=" ")
    traverse(root.right)


s = Solution()
trees = s.generateTrees(3)

for tree in trees:
    traverse(tree)
    print()
