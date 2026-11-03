class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;
        for(string s : operations){
            if(s == "C"){
                st.pop();
            }
            else if(s == "D"){
                int x = 2 * stoi(st.top());
                string str = to_string(x);
                st.push(str);
            }
            else if(s == "+"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.push(to_string(x));
                st.push(to_string(x+y));
            }
            else {
                st.push(s);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += stoi(st.top());
            st.pop();
        }
        return sum;
    }
};