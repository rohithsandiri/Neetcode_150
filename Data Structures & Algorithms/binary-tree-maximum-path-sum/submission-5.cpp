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
    int dfs(TreeNode* root, int &max_sum){
        if(!root)return 0;
        max_sum = max(max_sum ,root->val );

        int left =dfs(root->left, max_sum);
        int right = dfs(root->right, max_sum);

        int sum = left + right + root->val;
        
        if(sum >= max_sum){
            max_sum = max(max_sum , sum);
        }
        
        if(max(left,right) + root->val  > 0)return max(left,right) + root->val;
        else return 0;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_sum= INT_MIN;
        dfs(root, max_sum);

        return max_sum;
    }
};
