class Solution {
public:
    int numSquares(int n) {
        
        vector<int> coins ;
        int c = 1 ;
        while(c <= 100){
            coins.push_back(c * c) ;
            c++ ;
        }
        
        int dp[n + 1] ;
        dp[0] = 0 ;
        for(int i = 1 ; i <= n ; i++)
            dp[i] = i ;
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j < c ; j++){
                if(i < coins[j])
                    break ;
                // cout << i - coins[j] << " " ;
                dp[i] = min(dp[i] , dp[(i - coins[j])] + 1) ;
            }
            // cout << "\n" ;
        }
        
        return dp[n] ;
    }
};