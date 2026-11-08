class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>input;
        for(int i = 0;i < n; i++){
            input.push_back({position[i],speed[i]});
        }
        sort(input.begin(),input.end());
        reverse(input.begin(),input.end());
        vector<double>time;
        for(int i = 0;i < n; i++){
            int p = input[i].first;
            int s = input[i].second;
            double t = (double)(target - p)/(double)s;
            time.push_back(t);
        }
        stack<double>st;
        for(double x : time){
            if(!st.empty()){
                if(st.top() < x){
                    st.push(x);
                }
            }
            else st.push(x);
        }
        return st.size();
    }
};
