class Solution {
public:
    string shortestPalindrome(string s) {
        int m = s.size() , n = (2 * m) + 1 ;
        
        string rev = s ;
        reverse(rev.begin() , rev.end()) ;
        
        s.push_back('#') ;
        s += rev ;
        
        int lps[n] ;
        lps[0] = 0 ;
        int i = 1 , curr = 0 ;
        
        while(i < n){
            if(s[i] == s[curr]){
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
        
        int add = m - lps[n - 1] ;
        // cout << add << " " ;
        string str = rev.substr(0 , add) ;
        reverse(str.begin() , str.end()) ;
        rev += str ;
        
        return rev ;
    }
};