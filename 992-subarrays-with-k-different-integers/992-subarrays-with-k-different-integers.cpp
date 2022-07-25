class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        map<int , int> mp ;
        int n = nums.size() ;
        int c = 0 , lo = 0 , hi = 0 , curr = 0 , prev = 0 ;
        
        while(hi < n){
            if(mp.find(nums[hi]) == mp.end())
                curr++ ;
            
            mp[nums[hi]]++ ;
            
            while(curr > k){
                if(mp[nums[lo]] == 1)
                    curr-- ;
                mp[nums[lo]]-- ;
                if(curr == k)
                    mp.erase(nums[lo]) ;
                lo++ ;
                prev = 0 ;
            }
            
            while(mp[nums[lo]] > 1){
                prev++ ;
                mp[nums[lo]]-- ;
                lo++ ;
            }
            
            if(curr == k){
                c += (prev + 1) ;
            }
            hi++ ;
        }
        
        return c ;
    }
};