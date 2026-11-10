/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool dfs(TreeNode* p , TreeNode* q){
        if(!p && !q)return true;
        if(!p && q)return false;
        if(p && !q)return false;
        if(p -> val != q -> val)return false;
        // if(p -> left && q ->left && p -> left -> val != q -> left -> val)return false;
        // if(p -> right && q -> right && p -> right -> val != q -> right -> val)return false;
        bool left = dfs(p -> left, q -> left);
        bool right = dfs(p -> right, q -> right);
        return left && right;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
