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
    void dfs(TreeNode* root, int prev, int& count){
        if(!root)return;
        if(root->val >= prev)count++;
        int cur_max=max(prev,root->val);
        dfs(root->left,cur_max,count);
        dfs(root->right,cur_max,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        dfs(root,INT_MIN,count);
        return count;
    }
};
