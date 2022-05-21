class Solution {
public:
    int climbStairs(int n) {
        int c1  = 1 , c2 = 2 , c; 
        if(n == 1)
            return c1 ;
        
        if(n == 2)
            return c2 ;
        
        for(int i = 3 ; i <= n ; i++){
            c = c1 + c2 ;
            c1 = c2 ;
            c2 = c ;
        }
        return c ;
    }
};