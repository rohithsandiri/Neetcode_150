class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;int right=nums.size()-1;

        while(left<right){
            int mid=left + (right-left)/2;
            if(nums[mid]== target)return mid;

            if(nums[left] <= nums[mid]){
                //left part is sorted
                //check in sorted range
                if(nums[left] <= target && target < nums[mid]){
                    //target may lie in sorted range
                    right=mid;
                }
                else {
                    left=mid+1;
                }
            }
            //not in the left range

            else {
                //right part is sorted
                if(nums[mid] < target && target <=nums[right]){
                    left=mid+1;
                }
                else {
                    right=mid;
                }
            }
        }
        if(nums[left]==target)return left;
        if(nums[right] == target)return right;
        else return -1;
    }
};
