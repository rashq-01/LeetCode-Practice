class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& t : times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        minHeap.push({0,k});

        while(!minHeap.empty()){
            auto [D,currNode] = minHeap.top();
            minHeap.pop();

            for(auto& el : adj[currNode]){
                auto [v,d] = el;

                if(d+D < dist[v]){
                    dist[v] = d+D;
                    minHeap.push({d+D,v});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,dist[i]);
            if(ans==INT_MAX)return -1;
        }

        return ans;

    }
};