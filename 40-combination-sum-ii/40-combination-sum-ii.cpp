class Solution {
public:
    void solve(int pos, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& res){
        if(target==0) {
            res.push_back(comb);
            return;
        }
        for(int i=pos; i<candidates.size(); i++){
            if(candidates[i]>target) break;
            if(i>pos && candidates[i]==candidates[i-1]) continue;
            comb.push_back(candidates[i]);
            solve(i+1, target-candidates[i], candidates, comb, res);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        solve(0, target, candidates, comb, res);
        return res;
    }
};