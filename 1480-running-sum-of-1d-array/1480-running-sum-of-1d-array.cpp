class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> preSum ;
        preSum.push_back(nums[0]) ;
        
        int c = nums[0] ;
        for(int i = 1 ; i < nums.size() ; i++){
            c += nums[i] ;
            preSum.push_back(c) ;
        }
        return preSum ;
    }
};