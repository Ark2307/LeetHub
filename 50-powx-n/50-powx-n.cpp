class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1 ;
        
        if(n < 0){
            double res = 1.0 ;
            while(n){
                if(n % 2)
                    res /= x ;
                
                x *= x ;
                n /= 2 ;
            }
            return res ;
        }
        
        else{
            double res = 1.0 ;
            while(n){
                if(n % 2)
                    res *= x ;
                
                x *= x ;
                n /= 2 ;
            }
            return res ;
        }
    }
};