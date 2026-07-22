class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>& adj,vector<bool>& visited,stack<int>& st,vector<bool>& visitedPath,bool& flag){
        visited[u] = true;
        visitedPath[u] = true;
        for(auto& v : adj[u]){
            if(!visited[v])dfs(v,adj,visited,st,visitedPath,flag);
            if(flag)return;
            if(visitedPath[v]){
                flag = true;
                return;
            }
        }
        visitedPath[u] = false;
        st.push(u);
    }
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& ed : edges){
            adj[ed[1]].push_back(ed[0]);
        }

        stack<int> st;

        vector<bool> visited(V,false);
        vector<bool> pathVisited(V,false);
        bool flag = false;
        for(int i=0;i<V;i++){
            if(!visited[i])dfs(i,adj,visited,st,pathVisited,flag);
            if(flag)return {};
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

    }
};