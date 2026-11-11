class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x : stones){
            pq.push(x);
        }
        while(pq.size() >= 2){
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x == y)continue;
            int z = abs(x - y);
            pq.push(z);
        }
        if(!pq.empty())return pq.top();
        return 0;
    }
};
