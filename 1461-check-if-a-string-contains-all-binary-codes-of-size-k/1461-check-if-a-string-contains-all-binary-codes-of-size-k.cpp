class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size() ;
        set<string> si ;
        
        for(int i = 0 ; i < n - k + 1 ; i++)
        {
            string str = s.substr(i , k) ;
            //cout << str << " " ;
            si.insert(str) ;
        }
        
        int a = si.size() ;
        int val = 1 << k ;
        if(a == val)
            return 1 ;
        
        return 0 ;
    }
};