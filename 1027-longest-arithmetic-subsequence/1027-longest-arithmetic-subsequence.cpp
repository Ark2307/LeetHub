class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        
        vector<vector<int>> dp(1001, vector<int>(nums.size(), 1));
        
        int res = 2;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                auto diff = nums[j] - nums[i] + 500;
                dp[diff][j] = dp[diff][i] + 1;
                res = max(res, dp[diff][j]);
            }
        }
        return res;
    }
};