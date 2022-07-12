class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n = A.size() ;
    if(n < 2)
        return 0 ;
    int left[n] , right[n] ;
    int leftMini = A[0] ;
    
    
    
    left[0] = 0 ;
    
    for(int i = 1 ; i < n ; i++){
        left[i] = max(left[i - 1] , A[i] - leftMini) ;
        leftMini = min(leftMini , A[i]) ;
    }
    
    int rightMaxi = A[n - 1] ;
    
    right[n - 1] = 0 ;
    
    for(int i = n - 2 ; i >= 0 ; i--){
        right[i] = max(right[i + 1] , rightMaxi - A[i]) ;
        rightMaxi = max(rightMaxi , A[i]) ;
    }
    
    int maxi = right[0] ;
    
    for(int i = 1 ; i < n ; i++){
        int curr = left[i -1] + right[i] ;
        maxi = max(curr , maxi) ;
    }
    return maxi ;
    }
};