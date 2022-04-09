class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int lo = 0 , hi = n - 1 , res = 0;
        
        while(lo < hi){
            int val = min(height[lo] , height[hi]) ;
            val *= (hi - lo) ;
            
            res = max(val , res) ;
            if(height[lo] < height[hi]){
                lo++ ;
            }
            
            else
                hi-- ;
        }
        return res ;
    } 
};