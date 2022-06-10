class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size() ;
        for(int i = 0 ; i < n ; i++){
            arr[arr[i] % n] += n ;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(arr[i] >= (2 * n))
                return i ;
        }
        
        return n ;
    }
};