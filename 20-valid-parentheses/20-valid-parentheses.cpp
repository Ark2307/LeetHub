class Solution {
public:
    bool isValid(string s) {
        int n = s.size() ;
        stack<char> st ;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]) ;
            
            else if(st.empty()){
                return 0 ;
            }
            
            else{
                char c = st.top() ;
                st.pop() ;
                
                if(s[i] == ')' && c != '(')
                    return 0 ;
                
                if(s[i] == ']' && c != '[')
                    return 0 ;
                
                if(s[i] == '}' && c != '{')
                    return 0 ;
            }
        }
        if(st.empty())
            return 1 ;
        
        return 0 ;
    }
};