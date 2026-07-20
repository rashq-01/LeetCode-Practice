class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(V,0);
        for(auto& ed : edges){
            adj[ed[1]].push_back(ed[0]);
            indegree[ed[0]]++;
        }

        vector<int> ans;
        queue<int> q;
        int count = 0;

        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            count++;

            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }

        if(count!=V)return {};
        return ans;
    }
};