class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            string word=strs[i];
            sort(word.begin(),word.end());
            mp[word].push_back(i);
        }
        for(auto entry : mp){
            string name = entry.first;
            vector<string>temp;
            for(int val:entry.second){
                temp.push_back(strs[val]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
