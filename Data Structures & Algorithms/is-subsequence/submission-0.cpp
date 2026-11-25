class Solution {
private:
    bool isSub(string& s, string& t, int m, int n){
        if(m < 0)return true;
        if(n < 0)return false;
        if(s[m] == t[n])return isSub(s,t,m-1,n-1);
        else return isSub(s,t,m, n-1);

    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.size() - 1;
        int n = t.size() - 1;
        return isSub(s,t,m,n);
    }
};