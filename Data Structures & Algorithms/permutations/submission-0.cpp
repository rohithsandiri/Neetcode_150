class Solution {
    vector<vector<int>>result;
private:
    void solve(int index,vector<int>& nums,int n){
        if(index==n){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);//choose an index
            solve(index+1,nums,n);//explore
            swap(nums[index],nums[i]);//unchoose
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums,nums.size());
        return result;
    }
};
