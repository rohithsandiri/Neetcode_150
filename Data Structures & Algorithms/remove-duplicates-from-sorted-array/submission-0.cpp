class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;//distinct elements 
        int j = 1;//iteration 
        int n = nums.size();
        int k = 1;
        while(j < n){
            if(nums[i] == nums[j]){
                j++;
            }
            else if(nums[i] != nums[j]){
                i++;
                k++;
                nums[i] = nums[j];
                j++;
            }
        }
        return k;
    }
};