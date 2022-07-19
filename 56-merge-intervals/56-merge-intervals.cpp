class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int , int>> vi ;
        for(int i = 0 ; i < intervals.size() ; i++)
            vi.push_back({intervals[i][0] , intervals[i][1]}) ;
        
        sort(vi.begin() , vi.end()) ;
        int currSt = vi[0].first , currEn = vi[0].second ;
        vector<vector<int>>res ;
        
        int i = 1 ;
        int n = intervals.size() ;
        while(i < n){
            
            if(vi[i].first > currEn){
                vector<int> temp = {currSt ,currEn} ;
                res.push_back(temp) ;
                currSt = vi[i].first ;
                currEn = vi[i].second ;
                i++ ;
                continue ;
            }
            
            if(vi[i].first <= currEn)
            {
                currEn = max(currEn , vi[i].second) ;
                i++ ;
                continue ;
            }
        }
        
        vector<int> temp = {currSt ,currEn} ;
        res.push_back(temp) ;
        return res ;
    }
};