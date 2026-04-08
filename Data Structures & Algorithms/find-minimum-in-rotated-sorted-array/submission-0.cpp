class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left < right){
            mid=left + (right-left)/2;

            if(nums[left] > nums[mid]){ //unsorted
                right=mid;
            }
            else if(nums[mid] > nums[right]){
                //unosorted
                left=mid+1;
            }
            else break;
        }
        return nums[left];
    }
};
