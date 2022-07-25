class Solution {
public:
    
    void merge(vector<pair<int , int>> &arr , int lo , int mid , int hi , vector<int> &ans){
        int n = mid - lo + 1 ;
        int m = hi - mid ;
        
        vector<pair<int , int>> tempL , tempR ;
        for(int i = lo ; i <= mid ; i++)
            tempL.push_back(arr[i]) ;
        
        for(int i = mid + 1 ; i <= hi ; i++)
            tempR.push_back(arr[i]) ;
        
        int i = 0 , j = 0 , k = lo , curr = 0 ;
        
        while((i < n) && (j < m)){
            if(tempL[i].second <= tempR[j].second){
                ans[tempL[i].first] += curr ;
                arr[k++] = tempL[i++] ;
            }
            
            else{
                curr++ ;
                arr[k++] = tempR[j++] ;
            }
        }
        
        while(i < n){
            ans[tempL[i].first] += curr ;
            arr[k++] = tempL[i++] ;
        }
        
        
        while(j < m)
            arr[k++] = tempR[j++] ;
    }
    
    void mergeSort(vector<pair<int , int>> &arr , int lo , int hi , vector<int> &ans){
        
        if(lo >= hi)
            return ;
        
        int mid = (lo + hi) / 2 ;
        mergeSort(arr , lo , mid , ans) ;
        mergeSort(arr , mid + 1 , hi , ans) ;
        
        merge(arr , lo , mid , hi , ans) ;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size() ;
        vector<pair<int , int>> arr ;
        vector<int> ans(n) ;
        
        for(int i = 0 ; i < nums.size() ; i++)
            arr.push_back({i , nums[i]}) ;
        
        mergeSort(arr , 0 , n - 1 , ans) ;
        return ans ;
    }
};