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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(!root)return result;

        queue<TreeNode* >q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int i=0;

            while(i<size){
                TreeNode* temp=q.front();
                q.pop();

                if(i == 0){
                    result.push_back(temp->val);
                }

                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
                i++;
            }
        }
        return result;
    }
};
