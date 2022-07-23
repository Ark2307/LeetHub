class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size() , m = needle.size() ;
        
        
        int curr = 0 , i = 1 ; 
        int lps[m] ;
        lps[0] = 0 ;
        
        while(i < m){
            if(needle[i] == needle[curr]){
                curr++ ;
                lps[i] = curr ;
                i++ ;
            }
            
            else{
                if(curr != 0){
                    curr = lps[curr - 1] ;
                }
                
                else{
                    lps[i] = 0 ;
                    i++ ;
                }
            }
        }
        
        i = 0 ;
        int j = 0 ;
        
        while(i < n){
            if(haystack[i] == needle[j]){
                i++ ;
                j++ ;
            }
            
            if(j == m)
                return (i - m) ;
            
            if((i < n) && (needle[j] != haystack[i])){
                if(j != 0)
                    j = lps[j - 1] ;
                
                else
                    i++ ;
            }
        }
        
        return -1 ;
    }
};