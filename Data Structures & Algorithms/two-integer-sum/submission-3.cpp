class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp; //value, index;
        vector<int>result;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            int req = target - nums[i];
            if(mp.find(req) != mp.end()){
                result.push_back(mp[target-nums[i]]);
                result.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};
