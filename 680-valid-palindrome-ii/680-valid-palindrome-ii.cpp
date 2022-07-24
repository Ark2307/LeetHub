class Solution {
public:
    bool validPalindrome(string s) {
        int pos = -1 , n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] != s[n - 1 - i]){
                pos = i ;
                break ;
            }
        }
        
        if(pos == -1)
            return 1 ;
        
        string str1 = s.substr(0 , pos) ;
        string str2 = s.substr(pos + 1 , (n - pos - 1)) ;
        str1 += str2 ;
        // cout << str1 << " " << pos << " " ;
        
        int m = str1.size() ;
        bool flag = 0 ;
        
        for(int i = 0 ; i < m ; i++){
            if(str1[i] != str1[m - 1 - i]){
                flag = 1 ;
                break ;
            }
        }
        
        if(flag){
            flag = 0 ;
            int ind = n - 1 - pos ;
            string str3 = s.substr(0 , ind) ;
            string str4 = s.substr(ind + 1 , pos) ;
            
            // cout << str3 << " " << str4 << " " << ind  ;  
            str3 += str4 ;
            m = str3.size() ;
            // cout << " " << m ;
            
            for(int i = 0 ; i < m ; i++){
                if(str3[i] != str3[m - 1 - i]){
                    flag = 1 ;
                    break ;
                }
            }
            
            if(flag)
                return 0 ;
            return 1 ;
        }
        return 1 ;
    }
};