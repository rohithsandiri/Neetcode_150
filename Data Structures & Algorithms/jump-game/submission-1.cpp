class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest= 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(farthest < i)return false;
            farthest = max(nums[i] + i,farthest);
        }
        if(farthest >=n-1)return true;
        return false;
    }
};
