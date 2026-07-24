class Solution {
public:
    bool bfs(int u,unordered_map<int,vector<int>>& adj,vector<int>& color,int currColor){
        color[u] = currColor;
        queue<int> q;
        q.push(u);
        
        while(!q.empty()){
            int U = q.front();
            q.pop();
            for(auto& V : adj[U]){
                if(color[V] == color[U]){
                    return false;
                }
                else if(color[V] == -1){
                    color[V] = 1 - color[U];
                    q.push(V);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        unordered_map<int,vector<int>> adj;

        for(int u=0;u<V;u++){
            for(auto& v : graph[u]){
                adj[u].push_back(v);
            }
        }

        vector<int> color(V,-1);

        for(int u=0;u<V;u++){
            if(color[u]==-1 && !bfs(u,adj,color,1))return false;
        }

        return true;
    }
};