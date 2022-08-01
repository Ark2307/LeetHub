// #include <ext/pb_ds/assoc_container.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> 

// class Solution {
// public:
    
//     int countRangeSum(vector<int>& nums, int lower, int upper) {
//         ordered_set o_set;

// 		long long s = 0;
// 		o_set.insert(0);
// 		int Ans = 0;

// 		for(int i=0;i<nums.size();i++){
// 			s += nums[i];

// 			int LowerLt =  o_set.order_of_key((long long) (s - upper ));
// 			int UpperLt = o_set.order_of_key((long long)(s - lower+1));

// 			o_set.insert(s);
// 			Ans += UpperLt - LowerLt;

// 		}

// 		return Ans;
//     }
// };
#define ll long long

class Solution {
public:
    
    ll temp[100010] ;
    
    ll merge(vector<ll> &sum , int lower , int upper , int lo , int mid , int hi){
        ll count = 0 ;
        
        int rmin = mid + 1 , rmax = mid + 1 ;
        
        for(int i = lo ; i <= mid ; i++) {
            // update rightMin, so sums[rightMin] - sums[i] >= range.min
            while((rmin <= hi) && (sum[rmin] - sum[i]) < lower) {
                rmin++;
            }
            
            // update rightMax, so sums[rightMax] - sums[i] > range.max
            while((rmax <= hi) && ((sum[rmax] - sum[i]) <= upper)) {
                rmax++;
            }
            
            ll x = (rmax - rmin) ;
            count += x ;
        }
        
        for(int i = lo ; i <= hi ; i++)
            temp[i] = sum[i] ;
        
        int leftIndex = lo ;
        int rightIndex = mid + 1;
        
        for(int i = lo; i <= hi; i++) {
            if(leftIndex > mid) {
                sum[i] = temp[rightIndex++];
            } 
            else if(rightIndex > hi) {
                sum[i] = temp[leftIndex++];
            } 
            else if(temp[leftIndex] <= temp[rightIndex]) {
                sum[i] = temp[leftIndex++];
            } 
            else {
                sum[i] = temp[rightIndex++];
            }
        }
                
        return count;
        
    }
    
    ll mergeSort(vector<ll> &sum , int lower , int upper , int lo , int hi){
        
        if(lo == hi){
            return 0 ;
        }
        
        int mid = (lo + hi) / 2 ;
        ll count = 0 ;
        
        count += mergeSort(sum , lower , upper , lo , mid) ;
        count += mergeSort(sum , lower , upper , mid + 1 , hi) ;
        
        count += merge(sum , lower , upper , lo , mid , hi) ;
        
        return count ;
        
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        vector<ll> sum ;
        ll curr = 0 ;
        int n = nums.size() ;
        
        for(auto it: nums){
            sum.push_back(curr) ;
            curr += it ;
        }
        sum.push_back(curr) ;
        
        ll ans = mergeSort(sum , lower , upper , 0 , n ) ;
        return int(ans) ;
    }
};