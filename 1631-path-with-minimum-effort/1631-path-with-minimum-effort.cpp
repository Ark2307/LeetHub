#define pi pair<int ,pair<int , int>>

class Solution {
public:
    
    bool check(int x , int y , int n , int m){
        if(x < 0 || y < 0 || x >= n || y >= m)
            return 0 ;
        
        return 1 ;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size() , m = heights[0].size() ;
        
        vector<int> dx = {1 , -1 , 0 , 0} ;
        vector<int> dy = {0 , 0 , -1 , 1} ;
        
        priority_queue<pi , vector<pi> , greater<pi>> pq;
        
        vector<vector<bool>> visited(n , vector<bool>(m , 0)) ;
        int curr = 0 ;
        pq.push({0 ,{0 , 0}}) ;
        
        while(!pq.empty()){
            
            int val = pq.top().first ;
            int ro = pq.top().second.first ;
            int col = pq.top().second.second ;
            
            pq.pop() ;
            
            visited[ro][col] = 1 ;
            curr = max(curr , val) ;
            
            if(ro == (n - 1) && col == (m - 1)){
                return curr ;
            }
            
            for(int i = 0 ; i < 4 ; i++){
                
                int x = ro + dx[i] ;
                int y = col + dy[i] ;
                // cout << x << " " << y << " " ;
                
                if(check(x , y , n , m) && !visited[x][y]){
                    // visited[x][y] = 1 ;
                    int temp = abs(heights[x][y] - heights[ro][col]) ;
                    // cout << temp << " " << x << " "<< y << "\t";
                    pq.push({temp , {x , y}}) ;
                }
            }
        }
        return -1 ;
    }
};