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
    
    def isEqual(self, root_nodes, subroot_nodes):
        return root_nodes == subroot_nodes

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None and subRoot is None:
            return True
        
        nodes = []
        subroot_nodes = []

        nodes = self.dfs(root, nodes)
        subroot_nodes = self.dfs(subRoot, subroot_nodes)

        if self.isEqual(nodes, subroot_nodes):
            return True

        left_result = False
        right_result = False
        
        if root.left:
            left_result = self.isSubtree(root.left, subRoot)
        if root.right:
            right_result = self.isSubtree(root.right, subRoot)
        return left_result or right_result

        

        
        

        