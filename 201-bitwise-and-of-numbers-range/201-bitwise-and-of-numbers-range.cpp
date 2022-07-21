class Solution {
public:
    
    int funct(int n){
        int c = -1 ;
        while(n){
            n /= 2 ;
            c++ ;
        }
        return (1 << c) ;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        
        int ans = 0 ;
        
        while(left && right){
            int a = funct(left) , b = funct(right) ;
            if(a != b)
                break ;
            
            else{
                ans += a ;
                left ^= a ;
                right ^= b ;
            }
        }
            
        return ans ;
    }
};