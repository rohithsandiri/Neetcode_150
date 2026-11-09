# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    max_diam = 0
    def dfs(self,root):
        if root is None:
            return 0
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        self.max_diam = max(self.max_diam, left + right)
        return max(left,right) + 1
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.max_diam