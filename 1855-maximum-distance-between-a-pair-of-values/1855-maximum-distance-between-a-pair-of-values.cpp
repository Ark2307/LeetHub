class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int lo = 0 , hi = 0 , maxi = 0 , n = nums1.size() , m = nums2.size();
        while((lo < n) && (hi < m)){
            if(nums1[lo] <= nums2[hi]){
                maxi = max((hi - lo) , maxi) ;
                hi++ ;
            }
            
            else{
                lo++ ;
            }
        }
        
        return maxi ;
    }
};