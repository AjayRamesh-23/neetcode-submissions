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
        self.dfs(root.left, nodes)
        self.dfs(root.right, nodes)
        nodes.append(root.val)
        return nodes

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if root is None:
            return
        nodes = self.dfs(root, [])
        minimum = min(nodes)
        mapped_nodes = {}
        for index in range(len(nodes)):
            mapped_nodes[nodes[index] - minimum + 1] = nodes[index]
        return mapped_nodes[k]
