class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        string input;
        for(int i=0;i<n;i++){
            if(!isalnum(s[i]))continue;
            if(isupper(s[i]))input.push_back(tolower(s[i]));
            else input.push_back(s[i]);
        }
        string rev=input;
        reverse(rev.begin(),rev.end());
        if(input == rev)return true;
        else return false;
    }
};
