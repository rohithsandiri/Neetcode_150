class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        int L=0;
        int k=s1.size();
        for(char c:s1)mp[c]++;
        for(int R=0;R<s2.size();R++){
            mp[s2[R]]--;
            while(mp[s2[R]]<0){
                mp[s2[L]]++;
                L++;
            }
            if(R-L+1 == k)return true;
        }
        return false;
    }
};
