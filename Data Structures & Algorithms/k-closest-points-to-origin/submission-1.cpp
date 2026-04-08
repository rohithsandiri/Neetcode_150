class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>> , vector<pair<double, vector<int>>>, greater<pair<double,vector<int>>>>pq;
        //distance , {x,y} co-ordinates
        for(auto x : points){
            int a=x[0];
            int b=x[1];

            double dist = sqrt ( pow (a,2) + pow (b,2));
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
