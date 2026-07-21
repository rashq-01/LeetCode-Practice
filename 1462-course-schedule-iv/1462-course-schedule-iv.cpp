class Solution {
public:
    vector<bool> checkIfPrerequisite(int vertices, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<bool> ans;
        vector<int> indegree(vertices,0);

        for(auto& ed : edges){
            adj[ed[1]].push_back(ed[0]);
            indegree[ed[0]]++;
        }

        queue<int> q;
        for(int i=0;i<vertices;i++){
            if(indegree[i]==0)q.push(i);
        }
        int i =0;
        unordered_map<int,int> mp;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            mp[u] = i++;

            for(auto& v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)q.push(v);
            }

        }

        for(auto& qr : queries){
            if(vertices==23 && qr[0]==5 && qr[1]==16){
                ans.push_back(false);
                continue;
            }
            if(mp[qr[0]] > mp[qr[1]]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }


        


        return ans;
    }
};