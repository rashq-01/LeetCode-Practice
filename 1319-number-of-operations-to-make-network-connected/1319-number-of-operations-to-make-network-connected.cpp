class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int n){
        if(n == parent[n])return n;

        return parent[n] = find(parent[n]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y)return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        int count = 0;
        for(auto& ed : connections){
            int parent_x = find(ed[0]);
            int parent_y = find(ed[1]);
            if(parent_x == parent_y){
                count++;
                continue;
            }
            Union(parent_x,parent_y);
        }
        int vertex = 0;
        for(int i=0;i<n;i++){
            if(find(i) == i)vertex++;
        }
        vertex--;

        if(count<vertex)return -1;


        return vertex;
    }
};