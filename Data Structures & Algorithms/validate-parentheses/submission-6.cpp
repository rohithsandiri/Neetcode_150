class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else {
                if(st.empty())return false;
                char ch = st.top();
                if(c == ')' && ch != '('){
                    return false;
                }
                if(c == '}' && ch != '{'){
                    return false;
                }
                if(c == ']' && ch != '['){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty())return true;
        else return false;
    }
};
