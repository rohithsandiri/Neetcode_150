class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        //max(ignore last house, ignore first house);
        int two = nums[0];
        int one = max(nums[0],nums[1]);
        for(int i = 2; i < n - 1; i++){
            int temp = max(one, two + nums[i]);
            two = one;
            one = temp;
        }
        int rob1 = one;
        two = nums[1];
        one = max(nums[1],nums[2]);
        for(int i = 3; i < n; i++){
            int temp = max(one, two + nums[i]);
            two = one;
            one = temp;
        }
        int rob2 = one;
        return max(rob1,rob2);
    }
};
