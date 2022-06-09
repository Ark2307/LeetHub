class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0 ;
        
        
        int n = s.size() ;
        
        long long mod = 1e9 + 7 ;
        long long dp[n + 1] ;
        memset(dp , 0 , sizeof(dp)) ;
        
        dp[0] = 1 ;
        
        if(s[0] == '*')
            dp[1] = 9 ;
        
        else
            dp[1] = 1 ;
        
        for(int i = 2 ; i <= n ; i++){
            char curr = s[i - 1] , prev = s[i - 2] ;
            
            if(curr == '*')
               dp[i] += dp[i - 1] * 9 ;
            
            else if(curr > '0')
                dp[i] += dp[i - 1] ;
            
            if(prev == '1' || prev == '2'){
                if(curr == '*'){
                    if(prev == '1')
                        dp[i] += dp[i - 2] * 9 ;
                    
                    else
                        dp[i] += dp[i - 2] * 6 ;
                }
                
                else if((prev == '1') || (prev == '2' && curr < '7'))
                    dp[i] += dp[i - 2] ;
            }
            
            else if(prev == '*'){
                if(curr == '*'){
                    dp[i] += 15 * dp[i - 2] ;
                }
                
                else if(curr < '7')
                    dp[i] += (2 * dp[i - 2]) ;
                
                else
                    dp[i] += dp[i - 2] ;
            }
            
            dp[i] %= mod ;
        }
        
        return dp[n] ;
    }
};