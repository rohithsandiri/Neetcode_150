class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        for(int i = n-1; i >= 0; i --){
            if(i == n-1){
                int x = digits[i] + 1;
                digits[i] = x % 10;
                carry = x / 10;
            }
            else if(carry){
                int x = digits[i] + carry;
                digits[i] = x % 10;
                carry = x / 10;
            }
        }
        if(carry){
            digits.push_back(carry);
            reverse(digits.begin(), digits.end());
            reverse(digits.begin() + 1, digits.end());
        }
        return digits;
    }
};
