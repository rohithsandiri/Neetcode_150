# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = [];
        if root is None:
            return result
        q = deque()
        q.append(root)
        while q:
            size = len(q)
            while size:
                cur = q.popleft()
                if size == 1:
                    result.append(cur.val)
                size -= 1
                if cur.left is not None:
                    q.append(cur.left)
                if cur.right is not None:
                    q.append(cur.right)
        return result
        
        