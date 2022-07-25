class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        
        int c = 0 ;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            int lo = 0 , hi = i - 1 ;
            while(lo < hi){
                int s = nums[hi] + nums[lo] ;
                if(s <= nums[i]){
                    lo++ ;
                }
                
                else if(lo < hi){
                    c += (hi - lo) ;
                    // cout << c << " " ;
                    hi-- ;
                }
            }
        }
        
        return c ;
    }
};