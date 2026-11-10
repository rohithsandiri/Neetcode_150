# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self,root,p,q):
        if root is None:
            return None
        if root == p or root == q:
            return root
        left = self.dfs(root.left,p,q)
        right = self.dfs(root.right,p,q)
        if left is not None and right is not None:
            return root
        if left is not None and right is None:
            return left
        if left is None and right is not None:
            return right
        return None
        
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        return self.dfs(root,p,q)