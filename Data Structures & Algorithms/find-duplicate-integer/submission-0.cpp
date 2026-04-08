class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=abs(nums[i]);
            if(nums[x]>0){
                nums[x]=-nums[x];
            }
            else{
                break;
            }
        }
        return x;
    }
};
