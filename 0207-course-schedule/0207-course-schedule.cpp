class Solution {
public:
    bool dfs(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,vector<bool>& pathVisited){
        pathVisited[u] = true;
        visited[u] = true;

        for(auto& v : adj[u]){
            if(pathVisited[v])return true;
            if(!visited[v] && dfs(v,adj,visited,pathVisited))return true;
        }
        pathVisited[u] = false;
        return false;
    }
    bool canFinish(int V , vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        
        for(auto& ed : edges){
            adj[ed[1]].push_back(ed[0]);
        }

        vector<bool> pathVisited(V,false);
        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,pathVisited))return false;
        }

        return true;
    }
};