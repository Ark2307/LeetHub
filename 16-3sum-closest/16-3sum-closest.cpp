class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        
        
        // My Accepted approach .. TC - N2logn
        
//         vector<int>::iterator itr , itr1;
//         int res = INT_MAX ,ans;
        
//         for(int i = 0 ; i < n - 2 ; i++){
//             for(int j = i + 1 ; j < n - 1 ; j++){
//                 int val = target - nums[i] - nums[j] ;
//                 itr = nums.begin() ;
//                 advance(itr , j) ;
//                 itr++ ;
                
//                 itr1 = upper_bound(itr , nums.end() , val) ;
//                 //cout << itr1 - nums.begin() << " " << val << " " ;
//                 if(itr1 != nums.end())
//                 {
//                     int x = *itr1 ;
//                     int diff = abs(target - x - nums[i] - nums[j]) ;
//                     if(diff < res){
//                         res = diff ;
//                         ans = x + nums[i] + nums[j] ;
//                     }
//                 }
                
//                 if(itr1 != itr)
//                     itr1-- ;
                
//                 int x = *itr1 ;
//                 //cout << x << " " ;
//                 int diff = abs(target - x - nums[i] - nums[j]) ;
//                 if(diff < res){
//                     res = diff ;
//                     ans = x + nums[i] + nums[j] ;
//                 }
//             }
//         }
//         return ans ;
        
        // TC-> n2 {Two pointer Approach}
        
        int best = INT_MAX;
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int gap = nums[i] + nums[l] + nums[r] - target;
                if (abs(gap) < abs(best)) best = gap;
                else if (gap < 0)
                    ++l;
                else
                    --r;
            }
        }
        return target + best;
    }
};