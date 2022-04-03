class Solution {
public:
    string longestPalindrome(string str) {
        
        //Logical Approach
        
        int n = str.size() ;
        int maxi = 0 , start = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            int hi = i + 1 , lo = i - 1 ;
            
            while(lo >= 0 && str[i] == str[lo])
                lo-- ;
            
            while(hi < n && str[i] == str[hi])
                hi++ ;
            
            while(lo >= 0 && hi < n && str[lo] == str[hi]){
                lo-- ;
                hi++ ;
            }
            
            if((hi - lo - 1) > maxi){
                start = lo + 1 ;
                maxi = hi - lo - 1; 
            }
        }
        
        string res1 = str.substr(start , maxi) ;
        
        
        // Now I will try with the DP approach
        bool dp[n][n] ;
        memset(dp , 0 , sizeof(dp)) ;
        
        //dp[i][j] denotes if substr from i to j is palindrome
        
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1 ;
        }
        
        int startIn = 0 , maxi1 = 1 ;
        
        for(int i = 0 ; i < n - 1; i++){
            if(str[i] == str[i + 1])
            {
                startIn = i ;
                dp[i][i + 1] = 1 ;
                maxi1 = 2 ;
            }
        }
        
        for(int len = 3 ; len <= n ; len++){
            for(int start = 0 ; start <= (n - len) ; start++){
                int end = start + len - 1 ;
                
                if(str[start] == str[end] && dp[start + 1][end - 1]){
                    dp[start][end] = 1 ;
                    if(len > maxi1){
                        startIn = start ;
                        maxi1 = len ;
                    }
                }
            }
        }
        
        string res2 = str.substr(startIn , maxi1) ;
        
        return res2 ;
        
    }
};