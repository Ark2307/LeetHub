#define ll long long

class Solution {
public:
    bool intersect(vector<int> c1 , vector<int> c2){
        
        ll x = c2[0] - c1[0] ;
        ll y = c2[1] - c1[1] ;
        ll r = c1[2] ;
        
        x *= x , y *= y , r *= r ;
        
        x += y ;
        
        if(x <= r)
            return 1 ;
        
        return 0 ;
        
    }
    
    void bfs(int src, vector<vector<int>> &adj , vector<bool> &visited){
        
        queue<int> qu ;
        qu.push(src) ;
        
        visited[src] = 1 ;
        
        while(!qu.empty()){
            
            int x = qu.size() ;
            while(x--){
                
                int root = qu.front() ;
                qu.pop() ;
                
                for(auto it: adj[root]){
                    if(!visited[it]){
                        qu.push(it) ;
                        visited[it] = 1 ;
                    }
                }
            }
            
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size() ;
        vector<vector<int>> adj(n + 1) ;
        
        for(int i = 0 ; i < n ; i++){
            
            for(int j = 0 ; j < n ; j++){
                
                if(i != j){
                    
                    if(intersect(bombs[i] , bombs[j])){
                        adj[i].push_back(j) ;
                    }
                    
                }
                
            }
        }
        
        int maxi = 1 ;
        for(int i = 0 ; i < n ; i++){
            
            if(!adj[i].empty()){
                // cout << i << " " << adj[i][0] << "\n" ;
                vector<bool> visited(n + 1 , 0) ;
                bfs(i , adj , visited) ;
                
                int c = 0 ;
                for(int i = 0 ; i < n ; i++){
                    if(visited[i])
                        c++ ;
                }
                maxi = max(maxi , c) ;
            }
            
        }
        
        return maxi ;
        
    }
};