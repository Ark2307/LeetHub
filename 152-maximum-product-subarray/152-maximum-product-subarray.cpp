class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int maxi = 0 , maxEnd = 1 , minEnd = 1 ;
        int n = arr.size() ;
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > 0){
                maxEnd *= arr[i] ;
                minEnd = min(minEnd * arr[i] , 1) ;
            }
            
            else if(arr[i] == 0){
                maxEnd = 1 ;
                minEnd = 1 ;
            }
            
            else{
                int temp = maxEnd ;
                maxEnd = max(1 , minEnd * arr[i]) ;
                minEnd = temp * arr[i] ;
            }
            
            maxi = max(maxEnd , maxi) ;
        }
        
        if(maxi == 1){
            maxi = arr[0] ;
            for(int i = 1 ; i < n ; i++)
                maxi = max(maxi , arr[i]) ;
            
            bool flag = 0 ;
            for(int i = 0 ; i < n - 1 ; i++){
                if(arr[i] == -1 && arr[i + 1] == -1){
                    flag = 1 ;
                    break ;
                }
            }
            
            if(flag)
                maxi = 1 ;
        }
        
        return maxi ;
    }
};