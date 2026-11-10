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
    bool dfs2(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return true;
        if(!root)return false;
        if(!subRoot)return false;
        if(root -> val != subRoot -> val)return false;
        bool left = dfs2(root -> left, subRoot -> left);
        bool right = dfs2(root -> right, subRoot -> right);
        return left && right;
    }
    bool dfs1(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return true;
        if(!root)return false;
        if(root -> val == subRoot -> val){
            bool check = dfs2(root, subRoot);
            if(check)return true;
        }
        bool left = dfs1(root -> left, subRoot);
        bool right = dfs1(root -> right, subRoot);
        return left || right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs1(root, subRoot);
    }
};
