class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        int dp[n + 1] ;
        dp[0] = 0  ;
        
        if(n == 1)
            return nums[0] ;
        
        // take first and not last;
        dp[1] = nums[0] ;
        for(int i = 2 ; i < n ; i++){
            dp[i] = max(dp[i - 1] , dp[i - 2] + nums[i - 1]) ;
        }
        dp[n] = dp[n - 1] ; 
        
        int val = dp[n] ;
        dp[1] = 0 ;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = max(dp[i - 1] , dp[i - 2] + nums[i - 1]) ;
        }
        
        val = max(val , dp[n]) ;
        return val ;
    }
};