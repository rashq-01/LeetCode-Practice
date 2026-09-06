class Solution {
public:
    int m,n;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    const long long INF = 1e18;

    int minCost(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();


        vector<vector<vector<vector<long long>>>> dist(
            m,
            vector<vector<vector<long long>>>(
                n,
                vector<vector<long long>>(
                    4,
                    vector<long long>(k+1,INF)
                )
            )
        );

        using State = tuple<long long,int,int,int,int>;

        priority_queue<State,vector<State>,greater<State>> pq;

        if(m==1 && n==1)return grid[0][0];



        for(int dir=0;dir<4;dir++){
            int ni = 0 + dr[dir];
            int nj = 0 + dc[dir];

            if(ni<0 || ni>=m || nj<0 || nj>=n)continue;

            long long cost = grid[0][0] + grid[ni][nj];
            dist[ni][nj][dir][0] = cost;

            pq.push({cost,ni,nj,dir,0});
        }

        while(!pq.empty()){
            auto [cost,i,j,dir,turns] = pq.top();
            pq.pop();

            if(cost != dist[i][j][dir][turns])continue;

            for(int newDir=0;newDir<4;newDir++){
                int ni = i + dr[newDir];
                int nj = j + dc[newDir];

                if(ni < 0 || ni >= m || nj < 0 || nj >= n)continue;


                int newTurns = turns + (newDir != dir);

                if(newTurns > k)continue;

                long long newCost = cost + grid[ni][nj];

                if(newCost < dist[ni][nj][newDir][newTurns]){
                    dist[ni][nj][newDir][newTurns] = newCost;

                    pq.push({newCost,ni,nj,newDir,newTurns});
                }
            }
        }


        long long ans = INF;

        for(int dir=0;dir<4;dir++){
            for(int turns=0;turns<=k;turns++){
                ans = min(ans,dist[m-1][n-1][dir][turns]);
            }
        }

        return ans==INF ? -1 : ans;

    }
};