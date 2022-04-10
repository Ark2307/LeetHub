class Solution {
public:
    
    string longestPrefix(string str1 , string str2){
        int n = str1.size() , m = str2.size() ;
        string res = "" ;
        for(int i = 0 ; i < min(n , m) ; i++){
            if(str1[i] != str2[i])
                break ;
            
            res += str1[i] ;
        }
        return res ;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size() ;
        string res = strs[0] ;
        
        if(n == 1)
            return res ;
        
        
        for(int i = 0 ; i < n ; i++)
            res = longestPrefix(res , strs[i]) ;
        
        return res ;
    }
};