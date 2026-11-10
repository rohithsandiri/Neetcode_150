# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def dfs2(self,root,subRoot):
        if root is None and subRoot is None:
            return True
        if root is None and subRoot is not None:
            return False
        if root is not None and subRoot is None:
            return False
        if root.val != subRoot.val:
            return False
        left = self.dfs2(root.left,subRoot.left)
        right = self.dfs2(root.right,subRoot.right)
        return left and right
    def dfs1(self,root,subRoot):
        if root is None and subRoot is None:
            return True
        if root is None:
            return False
        if root.val == subRoot.val:
            check = self.dfs2(root,subRoot)
            if check is True:
                return True
        left = self.dfs1(root.left,subRoot)
        right = self.dfs1(root.right,subRoot)
        return left or right
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        return self.dfs1(root, subRoot)