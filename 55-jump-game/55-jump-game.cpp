class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        
        int currMaxi = nums[0] ;
        if(currMaxi >= (n - 1))
                return 1 ;
        for(int i = 1 ; i < n ; i++){
            if(currMaxi >= i){
                currMaxi = max(nums[i] + i , currMaxi) ;
            }
            
            if(currMaxi >= (n - 1))
                return 1 ;
        }
        
        
        return 0 ;
    }
};