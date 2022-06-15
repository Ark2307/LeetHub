class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size() , hi = n - 2 , lo = 1 , point = 0  , mid ;
    while(lo <= hi){
        mid = (lo + hi) / 2 ;
        if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
            return mid ;
            point = mid ;
            break ;
        }
        
        else if(A[mid] > A[mid - 1]){
            lo = mid + 1 ;
        }
        
        else
            hi = mid - 1 ;
    }
        return -1 ;
    }
};