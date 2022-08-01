#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> 

class Solution {
public:
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ordered_set o_set;

		long long s = 0;
		o_set.insert(0);
		int Ans = 0;

		for(int i=0;i<nums.size();i++){
			s += nums[i];

			int LowerLt =  o_set.order_of_key((long long) (s - upper ));
			int UpperLt = o_set.order_of_key((long long)(s - lower+1));

			o_set.insert(s);
			Ans += UpperLt - LowerLt;

		}

		return Ans;
    }
};