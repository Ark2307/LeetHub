class NumArray {
public:
    
    vector<int> seg ;
    int n ;
    
    void build(int ind , int lo , int hi , vector<int> &nums){
        
        if(lo == hi){
            seg[ind] = nums[lo] ;
            return ;
        }
        
        int mid = (lo + hi) / 2 ;
        
        build((2 * ind) + 1 , lo , mid , nums) ;
        build((2 * ind) + 2 , mid + 1 , hi , nums) ;
        
        seg[ind] = seg[(2 * ind) + 2] + seg[(2 * ind) + 1] ;
         
    }
    
    int querySum(int ind , int lo , int hi , int l , int r){
        
        if(l > hi || r < lo){
            return 0 ;
        }
        
        if((l <= lo) && (r >= hi)){
            
            return seg[ind] ;
        }
        
        int mid = (lo + hi) / 2 ;
        int left = querySum(((2 * ind) + 1) , lo , mid , l , r) ;
        int right = querySum(((2 * ind) + 2) , mid + 1 , hi , l , r) ;
        
        return (left + right) ;
    }
    
    void queryUpdate(int ind , int lo , int hi , int pos , int val){
        
        if(pos < lo || pos > hi)
            return;
        
        if(lo == hi){
            if(lo == pos)
                seg[ind] = val;
            return;
        }

        int mid = (lo + hi) / 2 ;
        
        queryUpdate((2 * ind) + 1, lo , mid , pos , val) ; 
        queryUpdate((2 * ind) + 2 , mid + 1 , hi , pos , val) ;
        
        seg[ind] = seg[(2 * ind) + 1] + seg[(2 * ind)+ 2];
        
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size() ;
        if(n > 0){
            seg.resize(4 * n , 0) ;
            build(0 , 0 , n - 1 , nums) ;
        }
        
        
    }
    
    void update(int index, int val) {
        if(n == 0)
            return ;
        
        queryUpdate(0 , 0 , n - 1 , index , val) ;
    }
    
    int sumRange(int left, int right) {
        if(n == 0)
            return 0 ;
        return querySum(0 , 0 , n - 1 , left , right) ;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


