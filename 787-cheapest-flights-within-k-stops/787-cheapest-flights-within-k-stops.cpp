#define pi pair<int , pair<int , int>>


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        
        priority_queue<pi , vector<pi> , greater<pi>> pq; 
        vector<vector<pair<int , int>>> adj(n) ;
        
        for(auto it: flights)
            adj[it[0]].push_back({it[1] , it[2]}) ;
        
        pq.push({0 , {src , 0}}) ;
        vector<int> dist(n , INT_MAX) ;
        vector<int> stops(n , n + 1) ;
        
        stops[src] = 0 ;
        dist[src] = 0 ;
        
        while(!pq.empty()){
            
            int curr = pq.top().first; 
            int node = pq.top().second.first ;
            int stop = pq.top().second.second ;
            pq.pop() ;
            
            for(auto it: adj[node]){
                
                int val = it.second + curr ;
                // if we reached destination
                if(it.first == dest){
                    if(val < dist[dest] && stop <= k){
                        dist[dest] = val ;
                        pq.push({val , {dest , stop}}) ;
                    }
                }
                
                else if(val < dist[it.first] || stop < (stops[it.first] - 1)){
                    dist[it.first] = val ;
                    stops[it.first] = 1 + stop ;
                    pq.push({val , {it.first , stops[it.first]}}) ;
                }
                
            }
            
        }
        int res = dist[dest] ;
            if(res == INT_MAX) 
                return -1 ;
            
            return res ;     

    }
};