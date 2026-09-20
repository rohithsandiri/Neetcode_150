class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int right = n-1;
        int i = 0;
        while(i<=right){
            if(nums[i] == val){
                while(i < right && nums[right] == val)right--;
                swap(nums[i],nums[right]);
                right--;
            }
            i++;
        }
        return right + 1;
    }
};