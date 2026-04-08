class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>input;
        int n=position.size();
        for(int i=0;i<n;i++){
            input.push_back({position[i],speed[i]});
        }
        sort(input.begin(),input.end(),greater<>());
        stack<int>st;//index
        for(int i=0;i<n;i++){
            if(!st.empty()){
                int index=st.top();
                int x=input[index].first;
                int y=input[index].second;
                float ahead= (float)(target-x)/y;
                float cur= (float)(target-input[i].first)/input[i].second;
                if(cur > ahead)st.push(i);
            }
            else st.push(i);
        }
        return st.size();
    }
};
