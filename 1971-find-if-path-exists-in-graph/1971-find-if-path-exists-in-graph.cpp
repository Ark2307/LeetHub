class Solution {
public:
    
    
    bool dfs(int src , int dest , vector<int> (&adj)[200010] , vector<bool> &visited){
        
        if(src == dest)
            return 1 ;
        
        visited[src] = 1 ;
        
        for(auto it : adj[src]){
            
            if(!visited[it]){
                
                visited[it] = 1 ;
                
                if(dfs(it , dest , adj , visited))
                    return 1 ;
            }
        }
        return 0 ;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[200010] ;
        vector<bool> visited(n + 1 , 0) ;
        
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][1]].push_back(edges[i][0]) ;
            adj[edges[i][0]].push_back(edges[i][1]) ;
        }
        
        return dfs(source , destination , adj , visited) ;
        
    }
};