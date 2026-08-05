class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        if(visited[u])return;

        visited[u] = true;
        for(auto& V : adj[u]){
            dfs(V,adj,visited);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> adj;
        for(auto& ed : invocations){
            adj[ed[0]].push_back(ed[1]);
        }
        vector<bool> visited(n,false);

        dfs(k,adj,visited);

        bool status = false;
        for(auto& inv : invocations){
            if(visited[inv[0]] != visited[inv[1]]){
                status = true;
                break;
            }
        }
        vector<int> ans;
        if(status){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }

        for(int i=0;i<n;i++){
            if(!visited[i])ans.push_back(i);
        }

        return ans;
    }
};