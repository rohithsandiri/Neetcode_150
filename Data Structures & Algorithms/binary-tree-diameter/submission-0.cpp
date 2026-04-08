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
    int max_len=0;

private:
    int dfs(TreeNode* root){
        if(!root)return 0;

        int left=dfs(root->left);
        int right=dfs(root->right);

        max_len=max(left+right,max_len);
        
        return max(left,right) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_len;
    }
};
