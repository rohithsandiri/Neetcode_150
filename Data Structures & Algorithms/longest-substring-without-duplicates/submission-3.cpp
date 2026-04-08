class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int max_seen=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=start){
                start=mp[s[i]]+1;

            }
            mp[s[i]]=i;
            max_seen=max(max_seen,i-start+1);
        }
        return max_seen;
    }
};
