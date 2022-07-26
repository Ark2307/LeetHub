class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256 , 0) ;
        
        for(auto it : t)
            freq[it]++ ;
        
        int hi = 0 , lo = 0 , st = 0 , mini = INT_MAX , n = s.size() , c = t.size() ;
        
        
        while(hi < n){
            if(freq[s[hi]] > 0)
                c-- ;
            
            freq[s[hi]]-- ;
            
            while(c == 0){
                int val = hi - lo + 1 ;
                if(val < mini){
                    mini = val ;
                    st = lo ;
                }
                
                if(freq[s[lo]] == 0)
                    c++ ;
                
                freq[s[lo]]++ ;
                lo++ ;
            }
            hi++ ;
        }
        
        if(mini == INT_MAX)
            return "" ;
        
        string str = s.substr(st , mini) ;
        return str ;
    }
};