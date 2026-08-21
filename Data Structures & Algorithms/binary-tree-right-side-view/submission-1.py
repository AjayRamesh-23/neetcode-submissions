# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        nodes = {}

        def rightSideViewOfTree(root, nodes, level):
            if root is None:
                return
            if level not in nodes:
                nodes[level] = root.val
            if root.right:
                nodes = rightSideViewOfTree(root.right, nodes, level + 1)
            if root.left:
                nodes = rightSideViewOfTree(root.left, nodes, level + 1)
            return nodes
        
        nodes = rightSideViewOfTree(root, nodes, 0)
        return list(nodes.values())


