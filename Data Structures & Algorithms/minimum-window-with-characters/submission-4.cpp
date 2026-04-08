class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp2;//character, freq
        for(char c:t)mp2[c]++;
        int required=mp2.size();

        int left=0;
        int right =0;
        int n=s.size();
        int start=0;
        int min_len=INT_MAX;
        int formed=0;
        unordered_map<char,int>mp1;//for first string

        while(right<n){
            char c=s[right];
            mp1[s[right]]++;

            if(mp2.count(c) && mp1[c]==mp2[c]){
                //number of characters that occurred full freq;
                formed++;
            }

            while(formed == required){
                //first update the min length 
                if(right-left+1 < min_len){
                    min_len=min(min_len,right-left+1);
                    start=left;
                }

                //shrink it
                char ch=s[left];
                mp1[ch]--;

                //update formed
                if(mp2.count(ch) && mp1[ch] < mp2[ch])formed--;

                left++;

            }
            right++;
        }
        if(min_len == INT_MAX)return "";
        return s.substr(start,min_len);

    }
};
