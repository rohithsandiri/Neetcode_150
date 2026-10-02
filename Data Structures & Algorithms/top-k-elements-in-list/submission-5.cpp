class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp; // value, frequency
        vector<vector<int>>freq(10000); // to store elements at the resp index freq
        vector<int>result;
        for(int x : nums ){
            mp[x]++;
        }
        for(auto x : mp){
            freq[x.second].push_back(x.first);
        }
        for(int i = 9999; i >= 0; i--){
            if(k == 0)break;
            if(!freq[i].empty()){
                for(int x : freq[i]){
                    result.push_back(x);
                    k--;
                }
            }
        }
        return result;
    }
};
