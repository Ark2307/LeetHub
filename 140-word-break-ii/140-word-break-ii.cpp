class Solution {
public:
    
    void solve(set<string> st , string s , int i , int start , string curr , vector<string> &res){
        
        int len = i - start + 1 ;
        string temp = s.substr(start , len) ;
        char sp = ' ' ;
        if (i == s.size() - 1) {
            if(st.find(temp) != st.end()) {
                string str = curr ;
                str += temp ;
                res.push_back(str);
            }
            return;
        }

        if (st.find(temp) != st.end()) {
            string str = curr ;
            str += temp ;
            str.push_back(sp) ;
            
            solve(st , s , i + 1 , i + 1 , str , res );
        }
        solve(st, s , i + 1, start , curr , res);
        
        
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st ;
        for(auto it: wordDict){
            st.insert(it) ;
        }
        
        vector<string> res ;
        string curr = "" ;
        
        solve(st , s , 0 , 0 , curr , res) ;
        return res ;
        
    }
};