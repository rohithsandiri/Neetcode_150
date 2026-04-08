class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>result;
        for(string s:strs){
            string x=s;
            sort(s.begin(),s.end());
            mp[s].push_back(x);

        }
        for(auto x:mp){
            result.push_back(x.second);
        }
        return result;
    }
};
