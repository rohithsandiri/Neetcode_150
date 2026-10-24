class Solution {
private:
    int solve(int w, vector<int>&weights){
        int d = 0;
        int sum = 0;
        for(int x : weights){
            if(sum + x > w){
                d++;
                sum = x;
            }
            else {
                sum += x;
            }
        }
        return d + 1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int n = weights.size();
        int right = 0;
        for(int x : weights){
            left = max(left, x);
            right += x;
        }
        int min_w = INT_MAX;
        while(left <= right){
            int mid = left + (right - left)/2;
            int d = solve(mid,weights);
            cout << mid << " " << d << endl;
            if(d <= days){
                right = mid - 1;
                min_w = min(min_w, mid);
            }
            else{
                left = mid + 1;
            }
        }
        return min_w;
    }
};