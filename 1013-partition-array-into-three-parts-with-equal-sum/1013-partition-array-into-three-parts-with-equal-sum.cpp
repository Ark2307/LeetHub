class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0 ;
        int n = arr.size() ;
        for(int i = 0 ; i < n ; i++)
            sum += arr[i] ;
        
        if((sum % 3) != 0)
            return 0 ;
        
        int val = (sum / 3) ;
        // cout << val << " " ;
        int lo = 0 , hi = n - 1 ;
        int csum = 0 ;
        while(lo < hi){
            csum += arr[lo] ;
            lo++ ;
            if(csum == val)
                break ;
        }
        
        if(lo == hi)
            return 0 ;
        lo-- ;
        
        csum = 0 ;
        while(hi >= 0){
            csum += arr[hi] ;
            hi-- ;
            if(csum == val)
                break ;
        }
        hi++ ;
        
        if((hi - lo) > 1)
            return 1 ;
        return 0 ;
    }
};