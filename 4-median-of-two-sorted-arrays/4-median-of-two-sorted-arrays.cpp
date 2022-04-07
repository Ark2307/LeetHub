class Solution {
public:
    double funct(vector<int> nums1 , vector<int> nums2){
        int n = nums1.size() , m = nums2.size();
        
            int lo = 0 , hi = n , mid , x , median ;
            
            while(lo <= hi){
                mid = (lo + hi) / 2 ;
                x = ((m + n + 1) / 2) - mid ;
                
                if(x < 0){
                    hi = mid - 1 ;
                    continue ;
                }
                
                if(mid != n && x > 0 && nums2[x - 1] > nums1[mid]){
                    lo = mid + 1 ;
                }
                
                else if(mid > 0 && x < m && nums2[x] < nums1[mid - 1]){
                    hi = mid - 1 ;
                }
                
                else{
                    if(mid == 0)
                        median = nums2[x - 1] ;
                    
                    else if(x == 0)
                        median = nums1[mid - 1] ;
                    
                    else{
                        median = max(nums2[x - 1] , nums1[mid - 1]) ;
                    }
                    break ;
                }
            }
            
            if ((n + m) % 2 == 1)
                return (double)median;
            
            if (mid == n)
                return (median + nums2[x]) / 2.0;
         
            if (x == m)
                return (median + nums1[mid]) / 2.0;
     
            return (median + min(nums1[mid], nums2[x])) / 2.0;
 
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size() , y = nums2.size() ;
        
        if(x < y){
            return funct(nums1 , nums2) ;
        }
        
        return funct(nums2 , nums1) ;
    }
};