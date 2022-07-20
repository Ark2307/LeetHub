class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele , count = 0 , n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(count == 0){
                count = 1 ;
                ele = nums[i] ;
            }
            
            else if(ele == nums[i])
                count++ ;
            
            else
                count-- ;
        }
        
        count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == ele)
                count++ ;
        }
        
        n = (n + 1) / 2 ;
        if(count >= n)
            return ele ;
        
        return -1 ;
    }
};