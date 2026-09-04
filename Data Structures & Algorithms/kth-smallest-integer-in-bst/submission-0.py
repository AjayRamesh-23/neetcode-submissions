# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, nodes):
        if root is None:
            return
        nodes.append(root.val)
        self.dfs(root.left, nodes)
        self.dfs(root.right, nodes)
        return nodes

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if root is None:
            return
        nodes = self.dfs(root, [])
        nodes.sort()
        if len(nodes) == 1:
            return nodes[0]
        return nodes[k-1]
        