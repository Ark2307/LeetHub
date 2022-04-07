class Solution {
public:
    
    double slope(int x1 , int y1 , int x2 , int y2){
        int maxi = INT_MAX ;
        double inf = maxi * 1.0 ;
        
        if(x1 == x2){
            return inf ;
        }
        
        double m = ((y2 - y1) * 1.0) / (x2 - x1) ;
        return m ;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        if(n == 1){
            return 1 ;
        }
        
        int maxi = 0 ;
        map<double , int> mp ;
        
        for(int i = 0 ; i < n - 1; i++){
            int currLen = 0 ;
            for(int j = i + 1 ; j < n ; j++){
                double val = slope(points[i][0] , points[i][1] , points[j][0] , points[j][1]) ;
                mp[val]++ ;
                currLen = max(currLen , mp[val]) ;
            }
            mp.clear() ;
            maxi = max(currLen , maxi);
        }
        return maxi + 1;
    }
};