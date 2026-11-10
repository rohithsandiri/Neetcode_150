# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self,root,max_seen):
        if root is None:
            return
        if root.val >= max_seen:
            self.count += 1
            max_seen = max(max_seen, root.val)
        self.dfs(root.left,max_seen)
        self.dfs(root.right,max_seen)
    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0
        self.dfs(root,float('-inf'))
        return self.count