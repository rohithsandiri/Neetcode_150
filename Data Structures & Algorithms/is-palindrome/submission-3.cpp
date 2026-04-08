class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;int n=s.size();
        vector<int>input;
        while(i<n){
            if(!isalnum(s[i])){
                i++;continue;
            }
            input.push_back(tolower(s[i]));i++;
        }
        i=0;int j=input.size()-1;
        while(i<j){
            if(input[i]!=input[j])return false;
            i++;j--;
        }
        return true;
    }
};
