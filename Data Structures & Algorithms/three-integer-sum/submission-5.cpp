class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int first = nums[i];//first number
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                if(nums[left] + nums[right] == -first){
                    vector<int>temp;
                    temp.push_back(first);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    left++;
                    while(left < right && nums[left] == nums[left - 1])left++;
                    right--;
                    while(left < right && nums[right] == nums[right+1])right--;
                }
                else if (nums[left] + nums[right] > -first ){
                    right--;
                }
                else left ++;
            }
        }
        return result;
    }
};
