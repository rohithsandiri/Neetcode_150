class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map< int, int>mp;//num,freq
        for(int x : nums){
            mp[x]++;
        }
        vector<int>result;
        int n = nums.size();
        int a = floor(n/3);
        for(auto x : mp){
            if(x.second > a)result.push_back(x.first);
        }
        return result;
    }
};