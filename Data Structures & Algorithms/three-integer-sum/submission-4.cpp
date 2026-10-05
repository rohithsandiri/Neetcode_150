class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        for(int i = 0; i < n; i ++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            j = i + 1;
            k = n-1;
            while(j < k){
                if(nums[j] + nums[k] < -nums[i]){
                    j++;
                }
                else if (nums[j] + nums[k] > -nums[i]){
                    k--;
                }
                else if (nums[j] + nums[k] == -nums[i]){

                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])j++;
                    while(j < k && nums[j] == nums[k+1])k--;
                }
            }
        }
        return result;
    }
};
