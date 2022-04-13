class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator itr ;
        vector<int> res = {-1 , -1} ;
        
        if(nums.empty())
            return res ;
        
        itr = lower_bound(nums.begin() , nums.end() , target) ;
        if(itr == nums.end() || *itr != target)
            return res ;
        
        int val = itr - nums.begin() ;
        res[0] = val ;
        itr = upper_bound(nums.begin() , nums.end() , target) ;
        itr-- ;
        val = itr - nums.begin() ;
        res[1] = val ;
        return res ;
    }
};