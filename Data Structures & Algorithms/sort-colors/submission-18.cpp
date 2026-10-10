class Solution {
public:
    void sortColors(vector<int>& nums) {
        //i,j,k
        //0 to i 
        //k -> 2 place 2 in kth index and k--
        //j -> 1 place 1 in jth index and j++
        //i -> 0 place 0 in ith index and i++
        int i = -1;
        int j = 0;
        int n = nums.size();
        int k = n-1;
        while(j <= k){
            if(nums[j] == 2){
                while(k > j && nums[k] == 2)k--;
                swap(nums[j], nums[k]);
            }
            if(nums[j] == 0){
                while(j < k && nums[j] ==1)j++;
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        return ;
    }
};