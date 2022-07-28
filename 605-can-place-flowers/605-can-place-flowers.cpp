class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int si = arr.size() ;
        
        if(n == 0)
            return 1; 
        
        int c = 0 ;
        if(si == 1){
            if(arr[0])
                return 0 ;
            
            return 1 ;
        }
        
        if(arr[1] == 0 && arr[0] == 0){
            arr[0] = 1 ;
            c++ ;
        }
        
        if(arr[si - 1] == 0 && arr[si - 2] == 0){
            arr[si - 1] = 1 ;
            c++ ;
        }
        
        // cout << c << "\n" ;
            
        for(int i = 1 ; i < si - 1 ; i++){
            
            if(arr[i + 1] != 1 && arr[i - 1] != 1 && arr[i] == 0){
                arr[i] = 1 ;
                c++ ;
            } 
        }
        
        // for(int i = 0 ; i < si ; i++)
        //     cout << arr[i] << " " ;
        
        if(c >= n)
            return 1 ;
        
        return 0 ;
    }
};