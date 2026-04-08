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
private:
    bool dfs(TreeNode* root, TreeNode* &prev){
        if(!root)return true;

        bool left = dfs(root->left,prev);
        if(!left)return false;
        if(prev && prev->val >= root->val)return false;
        prev = root;

        bool right = dfs(root->right , prev);
        if(!right)return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return dfs(root,prev);
    }
};
