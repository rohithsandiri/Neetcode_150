class Solution {
private : 
    void dfs(vector<vector<int>> &result, int i , int n, vector<int>& nums, vector<int>& temp){
        if(i >= n)return;

        for(int x = i ; x < n; x++){
            temp.push_back(nums[x]);
            result.push_back(temp);
            dfs(result, x+1, n, nums, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> temp;
        result.push_back({});
        dfs(result, 0, nums.size(),nums, temp);
        return result;
    }
};
