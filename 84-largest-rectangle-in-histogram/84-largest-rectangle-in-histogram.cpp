class Solution {
public:
    int largestRectangleArea(vector<int>&arr) {
        
        int n = arr.size() ;
        
        stack<int> st ;
        vector<int> leftSmaller(n , -1) ;
        vector<int> rightSmaller(n , n) ;
        
        st.push(-1) ;
        
        int i = 0 ;
        while(i < n){
            while(!st.empty() && st.top() != -1 && arr[st.top()] > arr[i]){
                rightSmaller[st.top()] = i ;
                st.pop() ;
            }
            
            if(i > 0 && arr[i] == arr[i - 1])
                leftSmaller[i] = leftSmaller[i - 1] ;
            
            else
                leftSmaller[i] = st.top() ;
            
            st.push(i) ;
            i++ ;
        }
        
        // for(int i = 0 ; i < n ; i++){
        //     cout << leftSmaller[i] << " " ;
        // }
        // cout << "\n" ;
        // for(int i = 0 ; i < n ; i++){
        //     cout << rightSmaller[i] << " " ;
        // }
        // cout << "\n" ;
        
        int maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            int val = arr[i] * (rightSmaller[i] - leftSmaller[i] - 1) ;
            maxi = max(maxi , val) ;
        }
        
        return maxi ;
        
    }
};