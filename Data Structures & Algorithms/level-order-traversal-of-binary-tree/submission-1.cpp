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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>q;
        if(!root)return result;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                TreeNode* cur = q.front();
                temp.push_back(cur -> val);
                q.pop();
                if(cur -> left)q.push(cur -> left);
                if(cur -> right)q.push(cur -> right);
            }
            result.push_back(temp);
        }
        return result;
    }
};
