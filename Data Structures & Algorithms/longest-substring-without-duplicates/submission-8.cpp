class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int max_len = 0;
        unordered_map<char, int>mp;//char, index
        for(int i=0;i<n ; i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= start ){
                //already exists in the map and in the current window
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            max_len = max(max_len,  i - start + 1);
        }
        return max_len;
    }
};
