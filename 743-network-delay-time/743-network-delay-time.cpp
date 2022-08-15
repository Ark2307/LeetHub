#define pi pair<int , int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pi>> adj(n + 1) ;
        for(auto it: times){
            adj[it[0]].push_back({it[1] , it[2]}) ;
        }
        
        priority_queue<pi , vector<pi> , greater<pi>> pq ;
        pq.push({0 , k}) ;
        
        int maxi = INT_MAX ;
        vector<int> dist(n + 1 , maxi) ;
        dist[k] = 0 ;
        
        while(!pq.empty()){
            
            int curr = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;
            
            
            for(auto it: adj[node]){
                
                int val = curr + it.second ;
                if(val < dist[it.first]){
                    dist[it.first] = val ;
                    pq.push({val , it.first}) ;
                }
                
            }
            
        }
        
        int ans = 0 ;
        for(int i = 1 ; i <= n ; i++){
            ans = max(ans , dist[i]) ;
        }
        
        if(ans == maxi)
            ans = -1 ;
        
        return ans ;
    }
};