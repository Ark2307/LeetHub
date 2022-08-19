class Solution {
public:
    int minSteps(string s, string t) {
        
        int c = 0 ;
        vector<int> c1(26 , 0) ;
        vector<int> c2(26 , 0) ;
        
        for(int i = 0 ; i < s.size() ; i++){
            c1[s[i] - 'a']++ ;
            c2[t[i] - 'a']++ ;
        }
        
        for(int i = 0 ; i < 26 ; i++){
            c += abs(c2[i] - c1[i]) ;
        }
        
        c /= 2 ;
        return c; 
    }
};