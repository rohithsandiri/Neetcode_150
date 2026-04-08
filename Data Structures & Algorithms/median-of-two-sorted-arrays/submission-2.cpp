class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m > n) return findMedianSortedArrays(nums2,nums1);

        int low=0; int high = m;
        while(low  <= high){
            int m1=(low + high)/2;//elements in the left half
            int m2 = (m+n + 1)/2 - m1;//elements in the right half

            int l1=(m1==0)?INT_MIN: nums1[m1-1];
            int r1=(m1==m)?INT_MAX: nums1[m1];

            int l2=(m2 == 0)?INT_MIN: nums2[m2-1];
            int r2 = (m2 == n)? INT_MAX: nums2[m2];

            if(l1<= r2 && l2 <= r1){
                if((m+n)%2 == 0)return (max(l1,l2) + min(r1,r2))/2.0;
                else return (double)max(l1,l2);
            }
            else if(l1 > r2){
                high=m1-1;
            }
            else if(l2 > r1){
                low = m1+1;
            }
        }
        return -1;
    }
};
