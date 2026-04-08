class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>> , vector<pair<int, vector<int>>>, greater<pair<int,vector<int>>>>pq;
        //distance , {x,y} co-ordinates
        for(auto x : points){
            int a=x[0];
            int b=x[1];

            int dist = a*a + b*b ;
            pq.push({dist , {a,b}});
        }

        vector<vector<int>>result;
        while(k--){
            auto x= pq.top();
            pq.pop();

            result.push_back(x.second);
        }

        return result;
    }
};
