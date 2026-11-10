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
    int max_sum = INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left = max(0,dfs(root -> left));
        int right = max(0,dfs(root -> right));
        max_sum = max(left + right + root -> val, max_sum);
        return max(left,right) + root -> val;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};
