class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() ;
        int lo = 0 , hi = 0 , curr = 0 ;
        int maxi = 0 ;
        
        for(int i = 0 ; i < 26 ; i++){
            lo = 0 , hi = 0 , curr = 0 ;
            char c = ('A' + i) ;
            // cout << c << " " ;
            
            while(hi < n){
                if(s[hi] == c){
                    hi++ ;
                }
                
                else{
                    if(curr == k){
                        maxi = max(maxi , hi - lo) ;
                        while((lo < n) && (s[lo] == c)){
                            lo++ ;
                        }
                        lo++ ;
                        curr-- ;
                    }
                    
                    else{
                        hi++ ;
                        curr++ ;
                    }
                }
            }
            maxi = max(maxi , hi - lo) ;
            // cout << maxi << "\n" ;
        }
        
        return maxi ;
    }
};