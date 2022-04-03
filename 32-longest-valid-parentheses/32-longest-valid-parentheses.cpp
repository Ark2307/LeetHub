class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size() ;
        int maxi = 0 ;
        
        stack<int> st ;
        st.push(-1) ;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(')
                st.push(i) ;
            
            else{
                if(!st.empty())
                    st.pop() ;
                
                int temp = -1 ;
                if(!st.empty()){
                    temp = st.top() ;
                    maxi = max(maxi , i - temp) ;
                }
                
                else
                    st.push(i) ;
            }
        }
        return maxi ;
    }
};