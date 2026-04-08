class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;//index
        int n=temperatures.size();
        vector<int>result(n);
        for(int i=n-1;i>=0;i--){
            int a=temperatures[i];
            while(!st.empty() && a>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty() && a<temperatures[st.top()]){
                result[i]=st.top()-i;
                st.push(i);
            }
            else if(st.empty()){
                result[i]=0;
                st.push(i);
            } 
        }
        return result;
    }
};
