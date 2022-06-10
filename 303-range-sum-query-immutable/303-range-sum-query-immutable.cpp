class NumArray {
public:
    int preSum[10010] ;
    
    NumArray(vector<int>& nums) {
        preSum[0] = 0 ;
        int n = nums.size() ;
        for(int i = 1 ; i <= n ; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1] ;
    }
    
    int sumRange(int left, int right) {
        left++ ;
        right++ ;
        return (preSum[right] - preSum[left - 1]) ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */