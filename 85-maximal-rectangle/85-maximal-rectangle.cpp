class Solution {
public:
    
    int maxHistArea(vector<int> A){
        
        int n = A.size() ;
        
        vector<int> left(n , -1) ;
        vector<int> right(n , n) ;
        stack<int> st ;
        st.push(-1) ;
        
        int i = 0 ;
        
        while(i < n){
            while(!st.empty() && st.top() != -1 && A[st.top()] > A[i]){
                right[st.top()] = i ;
                st.pop() ;
            }
            
            if(i > 0 && A[i] == A[i - 1])
                left[i] = left[i - 1] ;
            
            else
                left[i] = st.top() ;
            
            st.push(i) ;
            i++ ;
        }
        
        int maxi = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            int val = A[i] * (right[i] - left[i] - 1) ;
            maxi = max(maxi , val) ;
        }
        
        return maxi ;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int> prev , curr ;
        int n = matrix.size() , m = matrix[0].size() ;
        
        for(int i = 0 ; i < m ; i++){
            prev.push_back((matrix[0][i] - '0')) ;
        }
        
        int maxi = maxHistArea(prev) ;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                if(matrix[i][j] == '1')
                    curr.push_back(prev[j] + 1) ;
                
                else
                    curr.push_back(0) ;
                
            }
            
            int val = maxHistArea(curr) ;
            maxi = max(maxi , val) ;
            prev.clear() ;
            prev = curr ;
            curr.clear() ;
        }
        
        return maxi ;
    }
};