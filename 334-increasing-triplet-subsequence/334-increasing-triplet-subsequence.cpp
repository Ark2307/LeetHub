class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int mini = nums[0] , n = nums.size() , maxi = INT_MAX ;
        
        if(n < 3)
            return 0 ;
        
        for(int i = 1 ; i < n ; i++){
            if(nums[i] <= mini){
                mini = nums[i] ;
                continue ;
            }
            
            if(nums[i] < maxi){
                maxi = nums[i] ;
            }
            
            else if(nums[i] > maxi)
                return 1 ;
        }
        return 0 ;
    }
};