class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; 
        int right = 0;
        int n = nums.size();
        int sum = 0;
        int min_len = INT_MAX;
        bool check = false;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                min_len = min(min_len, right - left + 1);
                check = true;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(check)return min_len;
        else return 0;
    }
};