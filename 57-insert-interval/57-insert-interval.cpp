class Solution {
    
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp ;
        
        int n = intervals.size() ;
        if(n == 0){
            temp.push_back(newInterval) ;
            return temp ;
        }
        
        if((intervals[0][0] > newInterval[0]) && (intervals[0][0] > newInterval[1])){
            temp.push_back(newInterval) ;
            for(int i = 0 ; i < n ; i++){
                temp.push_back(intervals[i]) ;
            }
            return temp;
        }
        
        if(intervals[n - 1][1] < newInterval[0]){
            for(int i = 0 ; i < n ; i++){
                temp.push_back(intervals[i]) ;
            }
            temp.push_back(newInterval) ;
            return temp;
        }
        
        int pos = n ;
        
        for(int i = 0 ; i < intervals.size() ; i++){
            if((intervals[i][0] < newInterval[0]) && (intervals[i][1] < newInterval[0]))
                temp.push_back(intervals[i]) ;
            
            else if((i != 0) && (newInterval[1] < intervals[i][0] && newInterval[0] > intervals[i -1][1])){
                temp.push_back(newInterval) ;
                pos = i ;
                break ;
            }
            
            else{
                int st = min(intervals[i][0] , newInterval[0]) ;
                int en ;
                if(intervals[i][1] >= newInterval[1]){
                    en = intervals[i][1] ;
                    vector<int> arr = {st , en} ;
                    temp.push_back(arr) ;
                    pos = i + 1 ;
                    break ;
                }
                
                else{
                    while((i < n) && (newInterval[1] >= intervals[i][0])){
                        i++ ;
                    }
                    en = max(newInterval[1] , intervals[min((n - 1) , i - 1)][1]) ;
                    vector<int> arr = {st , en} ;
                    temp.push_back(arr) ;
                    pos = i ;
                    break ;
                }
            }
        }
        
        for(int i = pos ; i < n ; i++)
            temp.push_back(intervals[i]) ;
        
        return temp ;
    }
};