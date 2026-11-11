class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int x : nums){
            pq.push(x);
            while(pq.size() > k){
                pq.pop();
            }
        }
        this->k =  k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};
