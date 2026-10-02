class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre;
        vector<int>suf(nums.size());
        vector<int>result;
        int prev = 1;
        for(int i = 0; i < nums.size(); i++){
            pre.push_back(nums[i] * prev);
            prev *= nums[i];
        }
        prev =1;
        for(int i =nums.size() -1 ; i >=0;i--){
            suf[i] = (nums[i]*prev);
            prev *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            int value = 1;
            if(i - 1 >= 0)value *= pre[i-1];
            if(i + 1 < nums.size())value *= suf[i +1];
            result.push_back(value);
        }
        return result;
    }
};
