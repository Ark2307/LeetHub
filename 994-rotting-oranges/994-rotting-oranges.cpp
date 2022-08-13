class Solution {
public:
    bool check(int x , int y , int n , int m){
        if(x < 0 || x >= n || y < 0 || y >= m)
            return 0 ;
        
        return 1 ;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
       
        vector<int> dx = {-1 , 1 , 0 , 0} ;
        vector<int> dy = {0 , 0 , -1 , 1} ;
        
        queue<pair<int , int>> qu ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2)
                    qu.push({i , j}) ;
            }
        }
        
        pair<int , int> temp = {-1 , -1} ;
        qu.push(temp) ;
        
        int ans = 0 ;
        
        while(!qu.empty()){
            bool flag = 0 ;
            
            while(qu.front() != temp){
                pair<int , int> curr = qu.front() ;
                qu.pop() ;
                
                for(int i = 0 ; i < 4 ; i++){
                    
                    int x = curr.first + dx[i] ;
                    int y = curr.second + dy[i] ;
                    
                    if(check(x , y , n , m)){
                        
                        if(grid[x][y] == 1){
                            if(!flag){
                                flag = 1 ;
                                ans++ ;
                            }
                            grid[x][y] = 2 ;
                            qu.push({x , y}) ;
                        }
                        
                    }
                    
                }
            }
            
            qu.pop() ;
            if(!qu.empty())
                qu.push(temp) ;
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1)
                    return -1 ;
            }
        }
        
        return ans ;
    }
};