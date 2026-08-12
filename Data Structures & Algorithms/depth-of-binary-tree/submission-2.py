# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrderTraversal(self, root, level, result):
        if root is None:
            return
        if(len(result) <= level):
            result.append([])
        result[level].append([root.val])
        self.levelOrderTraversal(root.left, level + 1, result)
        self.levelOrderTraversal(root.right, level + 1, result)
        return result


    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # DFS Solution
        # if root is None:
        #     return 0
        # if root and (root.left is None and root.right is None):
        #     return 1
        # leftDepth = 1 + self.maxDepth(root.left)
        # rightDepth = 1 + self.maxDepth(root.right)
        # return max(leftDepth, rightDepth)

        # BFS Solution
        if root is None:
            return 0
        result = []
        return len(self.levelOrderTraversal(root, 0, result))
        
        
   


        