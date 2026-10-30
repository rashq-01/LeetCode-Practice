class Solution {
public:
    typedef tuple<int,int,int> T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
        }

        vector<vector<int>> result(n , vector<int>(k+1,INT_MAX));

        priority_queue<T , vector<T>, greater<T>> minHeap;
        result[0][1] = 0;

        minHeap.push({0,0,1});

        while(!minHeap.empty()){
            auto [d , u , count] = minHeap.top();
            minHeap.pop();

            if(d > result[u][count])continue;
            if(u == n-1)return d;

            for(auto& vec : adj[u]){
                int v = vec[0];
                int wt = vec[1];

                int newCount = (labels[v] == labels[u]) ? count+1 : 1;

                if(newCount > k)continue;

                int newDist  = d + wt;

                if(newDist < result[v][newCount]){
                    result[v][newCount] = newDist;
                    minHeap.push({newDist , v,newCount});
                }
            }
        }

        return -1;
    }
};