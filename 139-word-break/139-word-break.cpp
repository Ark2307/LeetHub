class Solution {
public:
    
    int solve(vector<int> &dp , set<string> st , int i , string s){
        if(i == s.size())
            return 1 ;
        
        if(dp[i] != -1)
            return dp[i] ;
        
        string str ;
        for(int j = i ; j < s.size() ; j++){
            
            str += s[j] ;
            if(st.find(str) != st.end()){
                if(solve(dp , st , (j + 1) , s))
                    return dp[i] = 1 ;
            }
            
        }
        return dp[i] = 0  ;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size() ;
        vector<int> dp((n + 1), -1) ;
        
        set<string> st ;
        for(auto it: wordDict)
            st.insert(it) ;
        
        // cout << dp[n] << " " ;
        
        return solve(dp , st , 0 , s) ;
        
    }
};