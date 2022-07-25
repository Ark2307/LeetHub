class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        
        int c = 0 ;
        
        for(int i = 0 ; i < (n - 2) ; i++){
            for(int j = i + 1 ; j < (n - 1) ; j++){
                int key = nums[i] + nums[j] ;
                if(key > nums[n - 1]){
                    c += (n - j - 1) ;
                    continue ; 
                }
                
                auto itr = lower_bound(nums.begin() , nums.end() , key) ;
                itr-- ;
                int ind = itr - nums.begin() ;
                // cout << ind << " " ; 
                if(ind > j)
                    c += (ind - j) ;
            }
        }
        
        return c ;
    }
};