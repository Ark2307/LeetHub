class Solution {
public:
    string longestPalindrome(string str) {
        
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
        
        string res = str.substr(start , maxi) ;
        
        return res ;
        
    }
};