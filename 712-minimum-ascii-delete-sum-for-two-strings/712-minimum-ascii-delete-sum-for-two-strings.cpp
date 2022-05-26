class Solution {
public:
    
    int maxCostLcs(string s1 , string s2){
        int n = s1.size() , m = s2.size() ;
        int dp[n + 1][m + 1] ;
        
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0 ;
                
                else if(s1[i - 1] == s2[j - 1]){
                    int val = s1[i - 1] ;
                    dp[i][j] = dp[i - 1][j - 1] + val ;
                }
                
                else
                    dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ;
            }
        }
        
        return dp[n][m] ;
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size() ;
        int sum = 0 , val;
        
        for(int i = 0 ; i < n ; i++){
            val = s1[i] ;
            sum += val ;
        }
        
        for(int i = 0 ; i < m ; i++){
            val = s2[i] ;
            sum += val ;
        }
        
        val = maxCostLcs(s1 , s2) ;
        val *= 2 ;
        sum -=  val ;
        return sum ;
    }
};