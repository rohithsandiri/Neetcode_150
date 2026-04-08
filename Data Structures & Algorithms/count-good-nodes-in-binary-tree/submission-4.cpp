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
    void dfs(TreeNode* root, int prev_max, int &count){
        if(!root)return ;
        if(root->val >= prev_max){
            count++;
            prev_max = max(prev_max, root->val);
        }
        dfs(root->left, prev_max, count);
        dfs(root->right, prev_max, count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count =0;
        dfs(root, INT_MIN, count);
        return count;
    }
};
