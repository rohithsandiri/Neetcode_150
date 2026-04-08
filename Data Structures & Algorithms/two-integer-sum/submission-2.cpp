class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int y=target-nums[i];
            if(mp.find(y)!=mp.end()){
                result.push_back(mp[y]);
                result.push_back(i);
                return result;
            }
            else {
                mp[nums[i]]=i;
            }
        }
        return result;
    }
};
