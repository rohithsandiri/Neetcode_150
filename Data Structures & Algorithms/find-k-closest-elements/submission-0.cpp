class Solution {
private:
    int search(int low, int high, vector<int>& arr, int target){
        while(low <= high){
            int mid = low + (high - low)/2 ;
            if(arr[mid] == target)return mid;
            if(arr[mid] < target)low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>result;
        int right = search(0,n-1,arr,x);
        int left = right - 1;
        while(k--){
            int r_diff = INT_MAX;
            if(right < n){
                r_diff = min(r_diff, abs(x - arr[right]));
            }
            int l_diff = INT_MAX;
            if(left >= 0){
                l_diff = min(l_diff, abs(x - arr[left]));
            }
            if(left >= 0 && l_diff <= r_diff){
                left--;
            }
            if(right < n && l_diff > r_diff){
                right++;
            }
        }
        left = left + 1;
        right = right - 1;
        for(int i = left; i <= right;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};