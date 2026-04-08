class Solution {
    int calculate(int k, vector<int>& piles){
        int hours=0;
        for(int x:piles){
            hours= hours + (x+k-1 )/k ;
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //min and max of the piles
        int low=1;
        int high=INT_MIN;
        for(int x:piles){
            high=max(high,x);
        }

        while(low<high){
            int mid=(low+high)/2;
            int hours=calculate(mid,piles);
            if(hours <= h){
                high=mid;
            }
            else if(hours >h ){
                low = mid+1;
            }
        }
        return low;
    }
};
