class Solution {
public:
    int numOfWays(int n) {
        
        long long mod = 1e9 + 7 ;
        long long a = 6 , b = 6 , c2 , c3 , c = 12;
        
        for(int i = 1 ; i < n ; i++){
            c3 = 2 * (a + b) ;
            c2 = c3 + b ;
            
            c = (c2 + c3) ;
            c %= mod ;
            
            b = c2 ;
            a = c3 ;
            a %= mod ;
            b %= mod ;
        }
        
        return c ;
    }
};