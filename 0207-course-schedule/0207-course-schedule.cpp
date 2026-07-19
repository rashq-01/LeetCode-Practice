class Solution {
public:
    bool dfs(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,vector<bool>& pathVisited){
        visited[u] = true;
        pathVisited[u] = true;

        for(auto& v : adj[u]){
            if(pathVisited[v])return true;
            if(!visited[v] && dfs(v,adj,visited,pathVisited))return true;
        }
        pathVisited[u] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        unordered_map<int,vector<int>> adj;
        for(auto& ed : prerequisites){
            adj[ed[0]].push_back(ed[1]);
        }

        vector<bool> pathVisited(V,false);
        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,adj,visited,pathVisited))return false;
        }

        return true;
    }
};