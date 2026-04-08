class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int x:nums){
            pq.push(x);
        }

        int a;
        while(k--){
            a=pq.top();
            pq.pop();
        }
        return a;
    }
};
