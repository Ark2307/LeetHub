class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size() ;
        vector<int> count(26 , 0) ;
        for(auto it :s){
            count[it - 'a']++ ;
        }
        
        stack<int> st ;
        st.push(s[0]) ;
        count[s[0] - 'a']-- ;
        
        vector<bool> visited(26 , 0) ;
        visited[s[0] - 'a'] = 1 ;
        
        int i = 1 ;
        while(i < n){
            count[s[i] - 'a']-- ;
            if(!visited[s[i] - 'a']){
                
                while((!st.empty()) && (st.top() > s[i]) && (count[st.top() - 'a'] > 0) ){
                    char c = st.top() ;
                    visited[c - 'a'] = 0 ;
                    st.pop() ;
                }
                
                visited[s[i] - 'a'] = 1 ;
                st.push(s[i]) ;
            }
            i++; 
        }
        string res ;
        while(!st.empty()){
            res += st.top() ;
            st.pop() ;
        }
        
        reverse(res.begin() , res.end()) ;
        return res ;
    }
};