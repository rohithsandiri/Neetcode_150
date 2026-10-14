class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map< int , int > mp; //prefix, freq
        mp[0] = 1;
        int count = 0;
        int prefix = 0;
        for(int x : nums){
            prefix += x;
            if(mp.find(prefix - k) != mp.end()){
                count += mp[prefix - k];
            }
            mp[prefix]++;
        }
        return count;
    }
};