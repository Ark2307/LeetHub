class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size() ;
        int lo = 0 , hi = 0 , curr = 0 , maxi = 0 ;
        
        while(hi < n){
            if(nums[hi] == 1){
                hi++ ;
            }
            
            else{
                
                if(curr == k){
                    maxi = max(maxi , hi - lo) ;
                    while(nums[lo] == 1)
                        lo++ ;
                    
                    lo++ ;
                    curr-- ;
                }
                
                else{
                    curr++ ;
                    hi++ ;
                }
                
            }
        }
        
        maxi = max(maxi , hi - lo) ;
        return maxi ;
    }
};