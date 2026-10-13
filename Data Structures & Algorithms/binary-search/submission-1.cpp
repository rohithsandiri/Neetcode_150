class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ;
        int n = nums.size();
        int right = n-1;
        int mid = 0;
        while(left <= right){
            mid = left + (right - left )/2 ; 
            cout << mid <<endl;
            if(nums[mid] == target)return mid;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        return -1;
    }
};
