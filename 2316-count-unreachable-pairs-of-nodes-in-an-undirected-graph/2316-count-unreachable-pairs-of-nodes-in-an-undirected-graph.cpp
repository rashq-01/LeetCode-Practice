class Solution {
public:
    void countNodes(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,int& currNodes){
        if(visited[u])return;

        visited[u] = true;
        currNodes++;

        for(auto& V : adj[u]){
            countNodes(V,adj,visited,currNodes);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        vector<bool> visited(n,false);
        long long ans = 0;
        int totalNodes = 0;
        for(int i=0;i<n;i++){
            int currNodes = 0;
            countNodes(i,adj,visited,currNodes);
            ans += ((long long)totalNodes*currNodes);
            totalNodes+=currNodes;
        }

        return ans;
    }
};