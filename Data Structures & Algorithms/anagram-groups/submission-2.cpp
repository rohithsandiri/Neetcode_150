class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;//sorted string, anagram strings
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string cur = strs[i];
            sort(cur.begin(), cur.end());

            if(mp.find(cur) != mp.end())mp[cur].push_back(strs[i]);
            else mp[cur].push_back(strs[i]);
        } 

        vector<vector<string>>result;

        for(auto x : mp){
            result.push_back(x.second);
        }

        return result;
    

    }
};
