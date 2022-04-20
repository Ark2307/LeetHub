class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxEndhere = 0 , currSum = 0 ;
        int n = nums.size() , c = 0 ;
        for(int i = 0 ; i < n ; i++){
            maxEndhere += nums[i] ;
            c++ ;
            if(maxEndhere < 0)
            {
                maxEndhere = 0 ;
                c = 0 ;
            }
            
            if(maxEndhere > currSum)
                currSum = maxEndhere ;
        }
        
        if(c == 0 && currSum == 0){
            int maxi = nums[0] ;
            for(int i = 1 ; i < n ; i++){
                maxi = max(maxi , nums[i]) ;
            }
            return maxi ;
        }
        
        return currSum ;
    }
};