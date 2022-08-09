#define ll long long
const ll mod = 1e9 + 7 ;

class Solution {
public:
    
    int check(int hi , vector<int> &arr , int key){
        int lo = 0 , mid , x = hi ;
        while(lo <= x){
            
            mid = (lo + x) / 2 ;
            if(arr[mid] == key)
                return mid ;
            
            else if(arr[mid] > key)
                x = mid - 1 ;
            
            else
                lo = mid + 1; 
        }
        return -1 ;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size() ;
        ll dp[n] ;
        fill(dp , dp + n , 1) ;
        
        sort(arr.begin() , arr.end()) ;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                
                if((arr[i] % arr[j]) == 0){
                    int val = arr[i] / arr[j] ;
                    val = check(i , arr , val) ;
                    if(val != -1){
                        // cout << val << " " << j << " " << i << "\n" ;
                        ll x = (dp[j] * dp[val]) ;
                        dp[i] += x ;
                        dp[i] %= mod ; 
                    }
                }
                
            }
        }
        
        ll sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += dp[i] ;
            sum %= mod ;
        }
        
        return sum ;
    }
};