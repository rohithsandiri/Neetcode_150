    class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_map<int,int>mp; //value, exists/not_exists
            int n = nums.size();
            for(int i = 0;i<n;i++){
                if(mp[nums[i]] == 1)return true;
                mp[nums[i]]=1;
            }
            return false;
        }
    };