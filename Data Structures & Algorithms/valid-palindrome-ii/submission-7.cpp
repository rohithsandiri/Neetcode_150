class Solution {
private:
    bool check(string s, int left, int right){
        while(left < right){
            if(s[left] == s[right]){
                left ++;
                right --;
            }
            else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            if(s[left] != s[right]){
                return check(s,left+1,right) || check(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};