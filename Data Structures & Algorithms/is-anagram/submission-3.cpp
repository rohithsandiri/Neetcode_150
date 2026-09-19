class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char,int>mp;
        if(m != n)return false;
        for(int i = 0; i < m; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp){
            if(it.second)return false;
        }
        return true;
    }
};
