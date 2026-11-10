# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self,root,depth):
        if root is None:
            return
        if(len(self.result) == depth):
            self.result.append(root.val)
        self.dfs(root.right,depth+1)
        self.dfs(root.left,depth+1)
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.result = []
        self.dfs(root,0)
        return self.result