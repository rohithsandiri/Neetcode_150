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
    unordered_map<int, int> mp;//map values inorder with index
private:
    TreeNode* dfs(int preStart, int inStart, int inEnd, vector<int>& preorder){
        if(inStart > inEnd)return nullptr;
        int rootVal = preorder[preStart];
        int m = mp[rootVal];
        int leftSize = m - inStart;
        TreeNode* cur = new TreeNode(rootVal);
        cur -> left = dfs(preStart + 1, inStart, m-1, preorder);
        cur -> right = dfs(preStart + leftSize + 1, m + 1, inEnd, preorder);
        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i ++){
            mp[inorder[i]] = i;
        }
        return dfs(0,0,n-1,preorder);
    }
};
