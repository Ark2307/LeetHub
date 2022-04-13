class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        // first i will try to find the pivot element.
        
//         int lo = 0 , hi = n - 1 , mid , pivInd = -1;
//         while(lo <= hi){
//             mid = (lo + hi) / 2 ;
//             if(mid < hi && nums[mid] > nums[mid + 1]){
//                 pivInd = mid ;
//                 break ;
//             }
            
//             if(mid > lo && nums[mid] < nums[mid - 1]){
//                 pivInd = mid - 1; 
//                 break ;
//             }
               
//             if(nums[mid] > nums[lo])
//                lo = mid + 1 ;
               
//             else
//                hi = mid - 1 ;
//         }
        
//         //cout << pivInd << " " ;
        
//         hi = n - 1 , lo = pivInd + 1 ;
//         while(lo <= hi){
//             mid = (lo + hi) / 2; 
//             if(nums[mid] == target)
//                 return mid ;
            
//             if(nums[mid] > target)
//                 hi = mid - 1 ;
            
//             else
//                 lo = mid + 1 ;
//         }
               
//         hi = pivInd , lo = 0 ;
//         while(lo <= hi){
//             mid = (lo + hi) / 2; 
//             if(nums[mid] == target)
//                 return mid ;
            
//             if(nums[mid] > target)
//                 hi = mid - 1 ;
            
//             else
//                 lo = mid + 1 ;
//         }
//         return -1 ;
        
        
        // now without finding pivot element
        
        int lo = 0 , hi = n - 1 , mid ;
        while(lo <= hi){
            mid = (lo + hi) / 2 ;
            if(nums[mid] == target){
                return mid ;
            }
            
            if(nums[lo] <= nums[mid]){
                if(target >= nums[lo] && target <= nums[mid])
                    hi = mid - 1 ;
                
                else
                    lo = mid + 1 ;
            }
            
            else if(target >= nums[mid] && target <= nums[hi]){
                lo = mid + 1 ;
            }
            
            else
                hi = mid - 1 ;
        }
        
        return -1 ;
    }
};