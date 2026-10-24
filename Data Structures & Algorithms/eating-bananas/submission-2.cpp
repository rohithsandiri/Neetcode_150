class Solution {
private:
    long long solve(int mid , vector<int>& piles){
        long long sum = 0;
        for(int x : piles){

            sum = sum + (long long)ceil((double)x/mid);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int n = piles.size();
        int max_val = 0;
        for(int x : piles){
            max_val = max(max_val, x);
        }
        int high = max_val;
        int min_val = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long hours = solve(mid,piles);
            cout<<hours<<" "<<mid<<endl;
            if(hours <= h){
                min_val = min(min_val, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return min_val;
    }
};
