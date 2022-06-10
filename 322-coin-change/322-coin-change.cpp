class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long int dp[amount + 1] ;
        long long int n = coins.size() ;
        
        long long int MAXI = INT_MAX ;
        
        fill(dp , dp + (amount + 1) , MAXI) ;
        dp[0] = 0LL ;
        
        for(long long int i = 0 ; i <= amount ; i++){
            if(dp[i] != MAXI){
                for(long long int j = 0 ; j < n ; j++){
                    if((coins[j] + i) <= amount){
                        dp[coins[j] + i] = min(dp[coins[j] + i] , 1 + dp[i]) ;
                    }
                }
            }
        }
        if(dp[amount] == MAXI)
            return -1 ;
        
        return int(dp[amount]) ;
    }
};