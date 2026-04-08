class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxf=0;
        int len=0;
        int res=0;
        int L=0;
        for(int R=0;R<s.size();R++){
            mp[s[R]]++;
            maxf = max(maxf, mp[s[R]]);
            while(R-L+1 - maxf >k){
                mp[s[L]]--;
                L++;
            }
            res=max(res,R-L+1);
        }
        return res;
    }
};
