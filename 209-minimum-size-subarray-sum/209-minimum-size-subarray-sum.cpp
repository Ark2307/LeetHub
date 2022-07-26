class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int  lo = 0 , hi = 0 , n = nums.size() , sum = 0 ;
        
        int mini = n + 1 ;
        
        while(hi < n){
            sum += nums[hi] ;
            hi++ ;
            while(sum >= target){
                mini = min(mini , hi - lo) ;
                
                sum -= nums[lo] ;
                lo++ ;
            }
        }
        
        if(mini == n + 1)
            return 0 ;
        
        return mini ;
    }
};