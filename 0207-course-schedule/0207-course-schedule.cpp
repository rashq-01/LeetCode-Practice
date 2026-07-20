class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(V,0);

        for(auto& ed : edges){
            adj[ed[1]].push_back(ed[0]);
            indegree[ed[0]]++;
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }

        return V==count;

    }
};