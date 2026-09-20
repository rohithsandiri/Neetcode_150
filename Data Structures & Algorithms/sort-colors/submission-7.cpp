class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1; 
        int j = 0;
        int k = nums.size()-1;
        //i to j -> zeroes 
        //j to k -> ones 
        //k to n -> two's

        while(j <= k){
            if(nums[j] == 2){
                while(k>j && nums[k] == 2)k--;
                swap(nums[j], nums[k]);
                k--;
            }
            if(nums[j] == 0){
                while(j < k && nums[j] == 1)j++;
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
    }
};