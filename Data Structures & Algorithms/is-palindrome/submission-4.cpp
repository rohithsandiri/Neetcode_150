class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;int r = n-1;
        while(l <= r){
            while(l <= r && !isalnum(s[l]))l++;
            char ch1 = tolower(s[l]);
            while((l <= r && !isalnum(s[r])))r--;
            char ch2 = tolower(s[r]);
            if(l <= r && ch1 != ch2)return false;
            l++;r--;
        }
        return true;
    }
};
